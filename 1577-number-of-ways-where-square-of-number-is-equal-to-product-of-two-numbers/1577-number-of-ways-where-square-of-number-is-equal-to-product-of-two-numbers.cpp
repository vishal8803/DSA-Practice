class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<long long,int> mp1;
        map<long long,int> mp2;
        
        for(int i = 0; i < nums1.size(); i++) {
            mp1[(long long)nums1[i]*(long long)nums1[i]]++;
        }
        
        for(int j = 0; j < nums2.size(); j++) {
            mp2[(long long)nums2[j]*(long long)nums2[j]]++;
        }
        
        int count = 0;
        
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = i + 1; j < nums1.size(); j++) {
                count += mp2[(long long)nums1[i]*(long long)nums1[j]];
            }
        }
        
        for(int i = 0; i < nums2.size(); i++) {
            for(int j = i + 1; j < nums2.size(); j++) {
                count += mp1[(long long)nums2[i]*(long long)nums2[j]];
            }
        }
        
        return count;
    }
};
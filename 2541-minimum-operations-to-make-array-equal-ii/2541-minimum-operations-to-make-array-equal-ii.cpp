class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0) {
            if(nums1 != nums2) return -1;
            return 0;
        }
        long long s1 = 0;
        long long s2 = 0;
        
        for(int i : nums1) s1 += i;
        for(int i : nums2) s2 += i;
        
        if(s1 != s2) return -1;
        
        long long inc = 0;
        long long dec = 0;
        
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] == nums2[i]) continue;
            if(nums1[i] > nums2[i]) {
                long long diff = nums1[i] - nums2[i];
                if(diff%k != 0) return -1;
                dec += diff/k;
            }else {
                long long diff = nums2[i] - nums1[i];
                if(diff%k != 0) return -1;
                inc += diff/k;
            }
        }
        
        if(inc != dec) return -1;
        return inc;
    }
};
class Solution {
public:
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sum1 = 0, sum2 = 0;
        
        for(int i : nums1) {
            sum1 += i;
        }
        
        for(int j : nums2) {
            sum2 += j;
        }
        
        if(sum1 == sum2) return 0;
        if(sum2 > sum1) return minOperations(nums2, nums1);
        
        if(nums1.size() > 6 * nums2.size()) return -1;
        int count = 0;
        int i = nums1.size() - 1;
        int j = 0;
        
        while(i >= 0 or j < nums2.size()) {
            int c1 = -1;
            int c2 = -1;
            
            if(sum1 <= sum2) break;
            
            if(i >= 0) {
                c1 = nums1[i] - 1;
            }
            
            if(j < nums2.size()) {
                c2 = 6 - nums2[j];
            }
            
            if(c1 >= c2) {
                sum1 -= (nums1[i] - 1);
                i--;
            } else {
                sum2 += 6 - nums2[j];
                j++;
            }
            count++;
        }
        
        return count;
    }
};
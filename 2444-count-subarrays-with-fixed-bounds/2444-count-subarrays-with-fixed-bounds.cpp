class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        
        int mnIdx = -1;
        int mxIdx = -1;
        int start = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] < minK or nums[i] > maxK) {
                start = i + 1;
                mnIdx = -1;
                mxIdx = -1;
            }
            
            if(nums[i] == minK) {
                mnIdx = i;
            }
            
            if(nums[i] == maxK) {
                mxIdx = i;
            }
            
            ans += max(0LL, (long long)min(mnIdx, mxIdx) - start + 1);
        }
        
        return ans;
    }
};
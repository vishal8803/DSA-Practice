class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        
        if(nums[0]) prefix[0] = 1;
        else prefix[0] = 0;
        
        if(nums[n-1]) suffix[n-1] = 1;
        else suffix[n-1] = 0;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i]) {
                prefix[i] = 1 + prefix[i-1];
            } else prefix[i] = 0;
        }
        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i]) suffix[i] = suffix[i+1] + 1;
            else suffix[i] = 0;
        }
        
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i==0) {
                count = max(count,suffix[i+1]);
            } else if(i==nums.size() - 1) {
                count = max(count,prefix[i-1]);
            } else {
                count = max(count,prefix[i-1] + suffix[i+1]);
            }
        }
        
        return count;
    }
};
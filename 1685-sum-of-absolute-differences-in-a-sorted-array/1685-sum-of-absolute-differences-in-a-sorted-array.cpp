class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0), suffix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        suffix[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i+1] + nums[i];
        }
        
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++) {
            if(i==0) {
                ans[i] = suffix[i+1] - nums[i]*(n-i-1);
            } else if(i==n-1) {
                ans[i] = nums[i]*i - prefix[i-1];
            } else {
                ans[i] = suffix[i+1] - nums[i]*(n-i-1) + nums[i]*i - prefix[i-1];
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        
        for(int i = 0; i < nums.size(); i++) {
            vector<int> temp = dp;
            for(int j : temp) {
                int sum = j + nums[i];
                dp[sum%3] = max(dp[sum%3], sum);
            }
        }
        
        return dp[0];
    }
};
class Solution {
public:
    int calc(vector<int> &nums, vector<vector<int>> &dp, int i, int k) {
        if(i==nums.size()) return 0;
        if(k < 0) return 1e9;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int cost = 1e9;
        int sum = 0;
        int mx = 0;
        
        for(int j = i; j < nums.size(); j++) {
            sum += nums[j];
            mx = max(mx, nums[j]);
            cost = min(cost, mx*(j-i+1) - sum + calc(nums, dp, j+1, k-1));
        }
        
        return dp[i][k] = cost;
    }
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return calc(nums, dp, 0, k);
    }
};
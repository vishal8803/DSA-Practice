class Solution {
public:
    int calc(vector<int>& stones, int i, int wt, vector<vector<int>> &dp) {
        if(i == stones.size() || wt < 0) return 0;
        
        if(dp[i][wt] != -1) return dp[i][wt];
        
        int res = calc(stones, i+1, wt, dp);
        if(stones[i] <= wt) {
            res = max(res, stones[i] + calc(stones, i+1, wt - stones[i], dp));
        }
        
        return dp[i][wt] = res;
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int i : stones) sum += i;
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        return sum - 2*calc(stones, 0, sum/2, dp);
    }
};
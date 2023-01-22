class Solution {
public:
    
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m));
        
        dp[0][0] = {grid[0][0], grid[0][0]};
        
        for(int i = 1; i < n; i++) {
            long long r = dp[i-1][0].first * (long long)grid[i][0];
            dp[i][0] = {r, r};
        }
        
        for(int j = 1; j < m; j++) {
            long long r = dp[0][j-1].first * (long long)grid[0][j];
            dp[0][j] = {r, r};
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                long long r1 = dp[i-1][j].first * (long long)grid[i][j];
                long long r2 = dp[i-1][j].second * (long long)grid[i][j];
                long long r3 = dp[i][j-1].first * (long long)grid[i][j];
                long long r4 = dp[i][j-1].second * (long long)grid[i][j];
                
                dp[i][j].first = max(max(r1, r2), max(r3, r4));
                dp[i][j].second = min(min(r1, r2), min(r3, r4));
            }
        }
        
        long long result = max(dp[n-1][m-1].first, dp[n-1][m-1].second);
        if(result < 0) return -1;
        
        int MOD = 1e9 + 7;
        
        return result%MOD;
    }
};
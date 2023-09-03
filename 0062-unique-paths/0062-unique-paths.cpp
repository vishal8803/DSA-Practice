class Solution {
public:
    int mod = 2 * 1e9;
    int calc(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i>=m || j>=n) return 0;
        
        if(i==m-1 && j==n-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = (calc(i+1, j, m, n, dp)%mod + calc(i, j+1, m, n, dp)%mod)%mod;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return calc(0,0, m, n, dp);
    }
};
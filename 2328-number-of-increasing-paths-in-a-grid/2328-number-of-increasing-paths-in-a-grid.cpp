class Solution {
public:
    int MOD = 1000000007;
    int count(int i, int j, vector<vector<int>> &grid, vector<vector<long long>> &dp, int prev){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]<=prev){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        return dp[i][j] =  (1%MOD + count(i+1,j,grid,dp,grid[i][j])%MOD + count(i,j+1,grid,dp,grid[i][j])%MOD + count(i-1,j,grid,dp,grid[i][j])%MOD + count(i,j-1,grid,dp,grid[i][j])%MOD)%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cnt += count(i,j,grid,dp,-1);
                cnt %= MOD;
            }
        }
        return cnt;
    }
};
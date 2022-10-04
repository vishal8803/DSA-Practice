class Solution {
public:
    int dp[201][201];
    int calc(vector<vector<int>> &grid, int i, int prev) {
        if(i==grid.size()) {return 0;}
        
        int mx = 20000;
        
        if(prev != -1 and dp[i][prev] != -1) return dp[i][prev];
        
        for(int j = 0; j < grid[i].size(); j++) {
            if(prev != -1 and prev==j) continue;
            mx = min(mx, grid[i][j] + calc(grid, i+1, j));
        }
        
        if(prev != -1) dp[i][prev] = mx;
        return mx;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int mx = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for(int j = 0; j < grid[0].size(); j++) {
            mx = min(mx, calc(grid, 0,-1));
        }
        
        return mx;
    }
};
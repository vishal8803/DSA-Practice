class Solution {
public:
    int dp[105][105];
    int n,m;
    
    bool isValid(int i, int j){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    
    int calc(vector<vector<int>> &grid, int i, int j){
        if(i==n) return j;
        
        if(isValid(i,j)==false){
            return -1;
        }
        
        if(grid[i][j]==1 && isValid(i,j+1) && grid[i][j+1]==1){
            if(dp[i+1][j+1] != -2) return dp[i+1][j+1];
            return dp[i+1][j+1] = calc(grid,i+1,j+1);
        }
        if(grid[i][j]==-1 && isValid(i,j-1) && grid[i][j-1]==-1){
            if(dp[i+1][j-1] != -2) return dp[i+1][j-1];
            return dp[i+1][j-1] = calc(grid,i+1,j-1);
        }
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                dp[i][j] = -2;
            }
        }
        
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            ans[i] = calc(grid,0,i);
        }
        
        return ans;
    }
};
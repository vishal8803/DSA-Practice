class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        int s=0;
        for(int j=m-1; j>=0; j--)
        {
            s=s+grid[n-1][j];
            dp[n-1][j]=s;
        }
        s=grid[n-1][m-1];
        for(int i=n-2; i>=0; i--)
        {
            s=s+grid[i][m-1];
            dp[i][m-1]=s;
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
            return dp[0][0];
    }
};
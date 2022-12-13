class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int i = 0; i < n; i++){
            dp[n-1][i]=matrix[n-1][i];    
        }
        
        for(int i = n-2; i >= 0; i--){
            
            for(int j=n-1; j>=0; j--){
                if(j==n-1){
                    dp[i][j]=matrix[i][j]+min(dp[i+1][j],dp[i+1][j-1]);
                }else if(j==0){
                    dp[i][j]=matrix[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                }else{
                    dp[i][j]=matrix[i][j]+min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1]));
                }
            }
        }
        
        int mn = INT_MAX;
        for(int j=0; j<n; j++){
            mn=min(mn,dp[0][j]);
        }
        return mn;
    }
};
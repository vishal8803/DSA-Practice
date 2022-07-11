class Solution {
public:
    long long dp[51][51][51];
    int MOD = 1000000007;
    long long countWays(int i, int j ,int m, int n, int moves){
        if(i<0 || j<0 || i>=m || j>=n){
            return 1;
        }
        
        if(moves==0){
            return 0;
        }
        if(dp[i][j][moves] != -1){
            return dp[i][j][moves]%MOD;
        }
        long long total = 0;
        
        total += (countWays(i+1,j,m,n,moves-1)%MOD + countWays(i,j-1,m,n,moves-1)%MOD + countWays(i,j+1,m,n,moves-1)%MOD + countWays(i-1,j,m,n,moves-1)%MOD)%MOD;
        
        dp[i][j][moves] = total%MOD;
        return total%MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        return countWays(startRow,startColumn,m,n,maxMove);
        
    }
};
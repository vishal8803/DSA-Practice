class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured==0)
            return 0;
        
        vector<vector<double>> dp(query_row+1);
        dp[0]=  vector<double>(1);
        dp[0][0]=poured;
        for(int i=1; i<=query_row; i++){
            dp[i]=vector<double>(i+1);
            for(int j=0; j<=i-1; j++){
                dp[i][j]+=dp[i-1][j]>1.0?(double)(dp[i-1][j]-1.0)/2.0:0;
                dp[i][j+1]+=dp[i-1][j]>1.0?(dp[i-1][j]-1.0)/2.0:0;
            }
        }
        for(int j=0; j<query_row+1; j++){
            if(dp[query_row][j]>1){
                dp[query_row][j]=1;
            }
        }
        
        return dp[query_row][query_glass];
    }
};
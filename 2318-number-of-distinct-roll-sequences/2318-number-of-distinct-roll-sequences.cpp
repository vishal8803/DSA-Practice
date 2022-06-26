class Solution {
    int dp[10001][7][7];
public:
    
    int calc(int n, int last, int lastToLast){
        if(n==0)
            return 1;
        
        if(dp[n][last][lastToLast] != 0)
            return dp[n][last][lastToLast];
        
        for(int i = 1; i <= 6; i++){
            if(i!=last && i!=lastToLast && (last==0 || __gcd(last,i)==1)){
                dp[n][last][lastToLast] = (dp[n][last][lastToLast] + calc(n-1,i,last))%1000000007;
            }
        }
        return dp[n][last][lastToLast];
    }
    
    int distinctSequences(int n) {
        memset(dp,0,sizeof(dp));
        return calc(n,0,0);
    }
};
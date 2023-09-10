class Solution {
public:
    int countOrders(int n) {
        long long dp[n+1];
        dp[0]=1;
        int MOD = 1000000007;
        
        for(int i = 1; i<=n; i++){
            dp[i] = i*dp[i-1]*(2*i-1);
            dp[i]%=MOD;
        }
        return dp[n];
    }
};
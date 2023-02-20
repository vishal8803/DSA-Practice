class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001][2];
    int calc(int i, int k, int n, bool start) {
        if(i >= n) return 0;
        
        if(k == 0) return 1;
        
        if(dp[i][k][start] != -1) return dp[i][k][start];
        
        long long ans = 0;
        
        if(start) {
            ans += calc(i, k, n, 0);
            ans += calc(i+1, k, n, 1);
            
        } else {
            ans += calc(i+1, k, n, 0);
            ans += calc(i+1, k-1, n, 1);
            
        }
        
        return dp[i][k][start] = ans%mod;
    }
    
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return calc(0, k, n,1);
    }
};
class Solution {
public:
    int MOD = 1000000007;
    int dp[31][31][1001];
    
    int ways(int n, int k, int target) {
        if(n==0 and target==0) return 1;
        
        if(n==0 || target <= 0) return 0;
        
        if(dp[n][k][target] != -1) return dp[n][k][target];
        
        long long total = 0;
        
        for(int i = 1; i <= k; i++) {
            total += ways(n-1,k,target - i);
            total %= MOD;
        }
        
        return dp[n][k][target] = total%MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return ways(n,k,target);
    }
};
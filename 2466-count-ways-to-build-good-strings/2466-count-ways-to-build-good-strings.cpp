class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1);
        dp[zero] += 1;
        dp[one] += 1;
        int MOD = 1e9 + 7;
        
        for(int i = 0; i <= high; i++) {
            if(i >= zero ) {
                dp[i] = (dp[i]%MOD + dp[i-zero]%MOD)%MOD;
            }
            if(i >= one) {
                dp[i] = (dp[i]%MOD + dp[i-one]%MOD)%MOD;
            }
            dp[i] %= MOD;
        }
        
        long long total = 0;
        for(int i : dp) {
            total += i;
        }
        
        for(int i = 0; i < low; i++) {
            total -= dp[i];
        }
        
        return total%MOD;
    }
};

/*
200
200
10
1
*/
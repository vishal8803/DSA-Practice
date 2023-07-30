class Solution {
public:
    int dp[101][11][2][2];
    int MOD = 1e9 + 7;
    
    int calc(string &s, int i, int prev, int tight, int zero) {
        if(i == s.size()) {
            return (zero != 1);
        }
        
        if(dp[i][prev+1][tight][zero] != -1) return dp[i][prev+1][tight][zero];
        
        int limit = (s[i] - '0');
        if(tight == 0) limit = 9;
        
        long long ans = 0;
        
        for(int currDigit = 0; currDigit <= limit; currDigit++) {
            int newTight = (tight && (currDigit == limit));
            int newZero = (zero && (currDigit == 0));
            if(zero or abs(currDigit - prev) == 1)
                ans = (ans%MOD + calc(s, i + 1, currDigit, newTight, newZero)%MOD)%MOD;
        }
        
        return dp[i][prev+1][tight][zero] = (ans%MOD);
    }
    
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        long long ans = calc(high, 0, -1, 1, 1);
        memset(dp, -1, sizeof(dp));
        ans -= calc(low, 0, -1, 1, 1);
        ans = (ans+MOD)%MOD;
        
        bool flag = true;
        
        for(int i = 1; i < low.size(); i++) {
            if(abs(low[i] - low[i-1]) != 1) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans = (ans + MOD + 1)%MOD;
        }
        
        return ans;
    }
};
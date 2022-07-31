class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        vector<vector<unsigned long long>> dp(n1+1, vector<unsigned long long>(n2+1));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n1; i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n1][n2];
    }
};
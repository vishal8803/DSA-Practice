class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; j++, i++) {
                if(g == 0) {
                    dp[i][j] = true;
                } else if(g == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    if(s[i] == s[j] and dp[i+1][j-1]) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = s.size() - 1; j >= 0; j--) {
                if(dp[0][i] and dp[j][s.size()-1] and dp[i+1][j-1]) return true;
            }
        }
        
        return false;
    }
};
class Solution {
public:
    int dp[101][101];
    
    int calc(string &s, int i, int j) {
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int minTurns = INT_MAX;
        for(int k = i; k < j; k++) {
            minTurns = min(minTurns, calc(s,i,k) + calc(s, k+1,j));
        }
        
        if(s[i] == s[j]) minTurns--;
        return dp[i][j] = minTurns;
    }
    
    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        return calc(s, 0, s.size() - 1);
    }
};
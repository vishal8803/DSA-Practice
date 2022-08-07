class Solution {
public:
    int calc(string &s, int idx, char prev, int k, vector<vector<int>> &dp) {
        if(idx == s.length()) return 0;
        
        if(prev != '#' && dp[idx][prev-'a'] != -1) return dp[idx][prev-'a'];
        
        if(prev=='#') {
            return max(1 + calc(s,idx+1,s[idx],k,dp), calc(s,idx+1,prev,k,dp));
        } else {
            if(abs(s[idx]-prev) <= k) {
                return dp[idx][prev-'a'] = max(1 + calc(s,idx+1,s[idx],k,dp), calc(s,idx+1,prev,k,dp));
            } else {
                return dp[idx][prev-'a'] = calc(s,idx+1,prev,k,dp);
            }
        }
        return 0;
    }
    
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length(),vector<int>(26,-1));
        return calc(s,0,'#',k, dp);
    }
};
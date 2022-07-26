class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool> dp(n);
        dp[0] = s[0]=='0';
        
        int reachable = 0;
        
        for(int i = 1; i < n; i++) {
            
            if(i>=minJump){
                reachable += dp[i-minJump] ? 1 : 0;
            }
            
            if(i>maxJump){
                reachable -= dp[i-maxJump-1] ? 1 : 0;
            }
            
            dp[i] = reachable && s[i]=='0';
        }
        
        return dp[n-1];
    }
};
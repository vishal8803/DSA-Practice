class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[s1.length()+1][s2.length()+1];
        dp[0][0]=0;
        for(int i=1; i<s1.length()+1; i++){
            dp[i][0]=s1[i-1]+dp[i-1][0];
        }
        
        for(int j=1; j<s2.length()+1; j++){
            dp[0][j]=s2[j-1]+dp[0][j-1];
        }
        
        for(int i=1; i<s1.length()+1; i++){
            for(int j=1; j<s2.length()+1; j++){
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j] = min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
                }
            }
        }
        
        return dp[s1.length()][s2.length()];
    }
};
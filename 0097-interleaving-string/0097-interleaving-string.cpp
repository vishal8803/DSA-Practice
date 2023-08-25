class Solution {
public:
    bool calc(string s1, string s2, string s3, int i, int j,vector<vector<int>> &dp){
        if(i==s1.length() && j==s2.length() && i+j==s3.length()){
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i<s1.length() && s1[i] == s3[i+j]){
            bool f1 = calc(s1,s2,s3,i+1,j,dp);
            if(f1){
                return dp[i][j] = true;
            }
        }
        
        if(j<s2.length() && s2[j] == s3[i+j]){
            bool f1 = calc(s1,s2,s3,i,j+1,dp);
            if(f1){
                return dp[i][j] = true;
            }
        }
        
        return dp[i][j] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1,-1));
        return calc(s1,s2,s3,0,0,dp);
    }
};
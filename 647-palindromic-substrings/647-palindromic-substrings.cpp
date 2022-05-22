class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j<n; j++,i++){
                if(i==j){
                    dp[i][j] = true;
                }else if(j == i+1){
                    if(s[i]==s[j]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        int count = 0;
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j<n; j++,i++){
                if(dp[i][j])
                    count++;
            }
        }
        return count;
    }
};
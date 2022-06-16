class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int g = 0; g <n; g++){
            for(int i = 0, j = g; j < n; j++, i++){
                if(g==0){
                    dp[i][j] = true;
                }else if(g==1){
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
        
        int ni,nj;
        int mx = INT_MIN;
        
        for(int g = 0; g <n; g++){
            for(int i = 0, j = g; j < n; j++, i++){
                if(dp[i][j]){
                    if(j-i+1 > mx){
                        mx = j - i + 1;
                        ni = i;
                        nj = j;
                    }
                }
            }
        }
        return s.substr(ni,mx);
    }
};
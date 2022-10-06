class Solution {
public:
    int numDecodings(string s) {
        int MOD = 1e9 + 7;
        int n = s.length();
        
        vector<long long> dp(n,0);
        
        if(s[0]=='*') {
            dp[0] = 9;
        } else if(s[0] != '0') {
            dp[0] = 1;
        }
        
        for(int i = 1; i < n; i++) {
            if(s[i] == '*' and s[i-1] == '*') {
                dp[i] = 9*dp[i-1] + 15*(i-2>=0?dp[i-2]:1);
                dp[i] %= MOD;
            }
            else if(s[i] == '*' and s[i-1] != '*') {
                dp[i] = dp[i-1] * 9;
                if(s[i-1]=='1') {
                    dp[i] += (i-2>=0?dp[i-2]:1) * 9;
                } else if(s[i-1]=='2') {
                    dp[i] += (i-2>=0?dp[i-2]:1) * 6;
                } 
            }
            else if(s[i] != '*' and s[i-1] == '*') {
                if(s[i] != '0') {
                    dp[i] += dp[i-1];
                }
                
                if(s[i]<='6') {
                    dp[i] += 2 * (i-2>=0?dp[i-2]:1);
                } else {
                    dp[i] += 1 * (i-2>=0?dp[i-2]:1);
                }
            } 
            else if(s[i] != '*' and s[i-1] != '*') {
                if(s[i] == '0' && s[i-1] == '0') {
                    dp[i] = 0;
                } else if(s[i] == '0' && s[i-1] != '0') {
                    if(s[i-1]>='1' && s[i-1]<='2'){
                        if(i-2>=0){
                            dp[i] = dp[i-2];
                        }else{
                            dp[i]=1;
                        }
                    }else{
                        dp[i] = 0;
                    }
                } else if(s[i] != '0' && s[i-1] == '0') {
                    dp[i] = dp[i-1];
                }else if(s[i] != '0' && s[i-1] != '0'){
                    dp[i] = dp[i-1];
                    int val = (s[i-1]-'0')*10 + (s[i]-'0');
                    if(val<=26){
                        if(i-2>=0)
                        dp[i] += dp[i-2];
                        else{
                            dp[i]+=1;
                        }
                    }
                }
            }
            
            dp[i] %= MOD;
        }
        
        return dp[n-1];
    }
};
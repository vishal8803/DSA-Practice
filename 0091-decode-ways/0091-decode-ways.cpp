class Solution {
public:
    int numDecodings(string s) {
       
        vector<int> dp(s.length(),0);
        
        if(s[0] >= '1' && s[0] <= '9') {
            dp[0] = 1;
        }
        
        if(s.length()==1)
            return dp[0];
        
        for(int i = 1; i < s.length(); i++) {
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
        
        return dp[s.length()-1];
    }
};
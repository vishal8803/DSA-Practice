class Solution {
public:
    void calc(string s, vector<vector<string>> &ans, vector<string> &temp, int i, vector<vector<bool>> &dp){
        if(i==s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int j=i; j<s.length(); j++){
            if(dp[i][j]){
                temp.push_back(s.substr(i,j-i+1));
                calc(s,ans,temp,j+1,dp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length()));
        for(int g=0; g<s.length(); g++){
            for(int i=0,j=g; j<s.length(); i++,j++){
                if(g==0){
                    dp[i][j]=true;
                }else if(g==1){
                    if(s[i]==s[j])
                    {
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> temp;
        calc(s,ans,temp,0,dp);
        return ans;
    }
};
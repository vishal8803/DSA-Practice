class Solution {
public:
    bool calc(string s,map<string,int> &mp,map<string,bool> &dp)
    {
        if(s=="")
            return true;
        
        if(mp.find(s)!=mp.end())
            return true;
        
        if(dp.find(s)!=dp.end())
            return dp[s];
        
        string temp = "";
        for(int i=0; i<s.length(); i++){
            temp=temp+s[i];
            
            if(mp.find(temp)!=mp.end()  && calc(s.substr(i+1),mp,dp))
                return dp[s] = true;
        }
        return dp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int> mp;
        for(string s : wordDict){
            mp[s]++;
        }
        map<string,bool> dp;
        return calc(s,mp,dp);
    }
};
class Solution {
public:
    bool compare(string &s1, string &s2){
        if(s1.size() != s2.size() + 1)
            return false;
        
        int i = 0;
        int j = 0;
        
        while(i<s1.size()){
            if(s1[i] != s2[j]){
                i++;
            }
            else{
                i++;
                j++;
            }
        }
        
        if(i==s1.size() && j==s2.size())return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        if(words.size()==1)
            return 1;
        
        sort(words.begin(), words.end(), [&](string s1, string s2){
            return s1.size() < s2.size();
        });
        
        vector<int> dp(words.size());
        dp[0] = 1;
        
        for(int i = 1; i < words.size(); i++){
            int mx = 0;
            for(int j = 0; j < i; j++){
                if(compare(words[i],words[j])){
                    mx = max(mx,dp[j]);
                }
            }
            dp[i] = 1 + mx;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
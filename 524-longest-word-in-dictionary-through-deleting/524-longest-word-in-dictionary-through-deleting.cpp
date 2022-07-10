class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        vector<int> freq(26,0);
        
        for(char ch : s){
            freq[ch-'a']++;
        }
        
        for(string t : dictionary){
            int i = 0;
            int j = 0;
            
            while(i<s.length() && j<t.length()){
                if(s[i]==t[j]){
                    j++;
                }
                i++;
            }
            
            if(j==t.length()){
                if(t.length() > ans.length()){
                    ans = t;
                }else if(t.length() == ans.length()){
                    if(ans > t){
                        ans = t;
                    }
                }
            }
        }
        return ans;
    }
};
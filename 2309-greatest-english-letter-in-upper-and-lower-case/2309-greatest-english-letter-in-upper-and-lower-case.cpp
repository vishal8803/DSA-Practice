class Solution {
public:
    string greatestLetter(string s) {
        vector<int> upper(26);
        vector<int> lower(26);
        
        for(char ch : s){
            if(ch>='a' && ch<='z'){
                lower[ch-'a']++;
            }else if(ch>='A' && ch<='Z'){
                upper[ch-'A']++;
            }
        }
        
        for(int i = 25; i>=0; i--){
            if(lower[i] != 0 && upper[i] != 0){
                char ch = ('A' + i);
                string ans = "";
                ans += ch;
                return ans;
            }
        }
        return "";
    }
};
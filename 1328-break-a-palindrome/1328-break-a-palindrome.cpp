class Solution {
public:
    bool palin(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    string breakPalindrome(string s) {
        if(s.length()==1) return "";
        
        string ans = "";
        
        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j < 26; j++) {
                if(s[i]==('a' + j)) {
                    continue;
                }
                string t = s;
                t[i] = 'a' + j;
                if(ans=="") ans = t;
                else if(!palin(t) && ans > t) ans = t;
                break;
            }
        }
        
        return ans;
    }
};
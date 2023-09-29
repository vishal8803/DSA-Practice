class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long sz = 0;
        for(char ch : s) {
            if(ch >= 'a' and ch <= 'z') {
                sz++;
            } else {
                sz *= (ch - '0');
            }
        }
        
        for(int i = s.size() - 1; i >= 0; i--) {
            k = k%sz;
            char ch = s[i];
            if(k == 0 and isdigit(s[i]) == false){
                string ans = "";
                ans += ch;
                return ans;
            }
            
            if(ch >= 'a' and ch <= 'z') {
                sz--;
            } else {
                sz /= (ch - '0');
            }
        }
        
        return "";
    }
};
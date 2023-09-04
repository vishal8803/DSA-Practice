class Solution {
public:
    char valid(string &s, int i, char limit, char c) {
        for(; c <= limit and ((i >= 1 and c == s[i-1]) || (i >= 2 and c == s[i-2])); c++);
        return c;
    }
    
    string smallestBeautifulString(string s, int k) {
        char limit = ('a' + k - 1);
        int n = s.size();
        
        for(int i = n - 1; i >= 0; i--) {
            char c = valid(s, i, limit, (s[i] + 1));
            if(c <= limit) {
                s[i] = c;
                for(int j = i + 1; j < n; j++) {
                    s[j] = valid(s, j, limit, 'a');
                }
                return s;
            }
        }
        
        return "";
    }
};
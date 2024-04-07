class Solution {
public:
    string getSmallestString(string s, int k) {
        if(k == 0) return s;
        
        for(int i = 0; i < s.size(); i++) {
            int ch = (s[i] - 'a');
            if(ch == 0) continue;
            int ch2 = (26-ch);
            int mn = min(ch, ch2);
            if(mn <= k) {
                s[i] = 'a';
                k -= mn;
            } else {
                s[i] = ('a' + (ch-k));
                k=0;
            }
        }
        
        return s;
    }
};
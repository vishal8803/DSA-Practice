class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        char prev = '#';
        
        while(true) {
            int mx = max(a, max(b,c));
            if(mx == 0) break;
            if(mx == a) {
                if(prev == 'a') {
                    int m = max(b,c);
                    if(m == 0) break;
                    if(m == b) {
                        ans += 'b';
                        b--;
                        prev = 'b';
                    } else {
                        ans += 'c';
                        c--;
                        prev = 'c';
                    }
                } 
                else {
                    ans += 'a';
                    a--;
                    if(a > 0) {
                        ans += 'a';
                        a--;
                    }
                    prev = 'a';
                }
            } 
            else if(mx == b) {
                if(prev == 'b') {
                    int m = max(a,c);
                    if(m == 0) break;
                    if(m == a) {
                        ans += 'a';
                        a--;
                        prev = 'a';
                    } else {
                        ans += 'c';
                        c--;
                        prev = 'c';
                    }
                } 
                else {
                    ans += 'b';
                    b--;
                    if(b > 0) {
                        ans += 'b';
                        b--;
                    }
                    prev = 'b';
                }
            } 
            else if(mx == c) {
                if(prev == 'c') {
                    int m = max(a,b);
                    if(m == 0) break;
                    if(m == a) {
                        ans += 'a';
                        a--;
                        prev = 'a';
                    } else {
                        ans += 'b';
                        b--;
                        prev = 'b';
                    }
                } 
                else {
                    ans += 'c';
                    c--;
                    if(c > 0) {
                        ans += 'c';
                        c--;
                    }
                    prev = 'c';
                }
            }
        }
        
        return ans;
    }
};
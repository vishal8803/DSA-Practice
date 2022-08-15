class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int i = 0;
        
        while(i < s.length()) {
            if(s[i]=='V') {
                ans += 5;
                i++;
            } else if(s[i]=='L') {
                ans += 50;
                i++;
            } else if (s[i]=='D') {
                ans += 500;
                i++;
            } else if(s[i]=='M') {
                ans += 1000;
                i++;
            } else if(s[i]=='I') {
                if(i+1 < s.size() && s[i+1]=='V') {
                    ans += 4;
                    i+=2;
                } else if(i+1 < s.size() && s[i+1]=='X') {
                    ans += 9;
                    i+=2;
                } else {
                    ans += 1;
                    i++;
                }
            } else if(s[i]=='X') {
                if(i+1 < s.size() && s[i+1]=='L') {
                    ans += 40;
                    i+=2;
                } else if(i+1 < s.size() && s[i+1]=='C') {
                    ans += 90;
                    i+=2;
                } else {
                    ans += 10;
                    i++;
                }
            } else if(s[i]=='C') {
                if(i+1 < s.size() && s[i+1]=='D') {
                    ans += 400;
                    i+=2;
                } else if(i+1 < s.size() && s[i+1]=='M') {
                    ans += 900;
                    i+=2;
                } else {
                    ans += 100;
                    i++;
                }
            }
        }
        return ans;
    }
};
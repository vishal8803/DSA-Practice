int dp[101][27][101][101];
class Solution {
public:
    
    string s;
    int calc(int i, int prev, int len, int k) {
        if(k < 0) return INT_MAX;
        if(i>=s.size()) return 0;
        
        if(dp[i][prev][len][k] != -1) return dp[i][prev][len][k];
        
        int r1 = calc(i+1, prev, len, k-1);
        int r2 = 0;
        
        if(s[i]-'a' == prev) {
            if(len == 1 || len == 9 || len == 99) {
                r2 += 1;
            }
            r2 += calc(i+1, prev, len+1, k);
        } else {
            r2 = 1 + calc(i+1, s[i]-'a', 1, k);
        }
        
        return dp[i][prev][len][k] = min(r1,r2);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s; 
        memset(dp, -1, sizeof(dp));
        return calc(0, 26, 0, k);
        
        
    }
};
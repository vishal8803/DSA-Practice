class Solution {
public:
    int numWays(string s) {
        int count = 0;
        for(char ch : s) if(ch == '1') count++;
        int n = s.size();
        
        int MOD = 1e9 + 7;
        
        if(count == 0) {
            long long temp = ((long long)(n-1)*(long long)(n-2))/2LL;
            return temp%MOD;
        }
        
        if(count%3 != 0) return 0;
        
        int ways1 = 0;
        int ways2 = 0;
        int curr = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') curr++;
            if(curr == count/3) {
                ways1++;
            } else if(curr == 2 * (count/3)) {
                ways2++;
            }
        }
        
        long long ways = ((long long)ways1%MOD*(long long)ways2%MOD)%MOD;
        return ways;
    }
};
class Solution {
public:
    int numSub(string s) {
        long long count = 0;
        int MOD = 1000000007;
        
        int i = 0;
        
        while(i < s.length()) {
            int cnt = 0;
            while(i < s.length() && s[i]=='1') {
                i++;
                cnt++;
            }
            i++;
            count += ((long long)(cnt)*(long long)(cnt+1))/2;
            count %= MOD;
        }
        
        return count;
    }
};
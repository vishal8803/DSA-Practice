class Solution {
public:
    int countHomogenous(string s) {
        long long count = 0;
        int MOD = 1e9 + 7;
        
        int i = 0;
        while(i < s.size()) {
            long long cnt = 0;
            char ch = s[i];
            
            while(i < s.size() and s[i] == ch) {
                cnt++;
                i++;
            }
            
            count += ((cnt)*(cnt+1))/2;
            count %= MOD;
        }
        
        return count;
    }
};
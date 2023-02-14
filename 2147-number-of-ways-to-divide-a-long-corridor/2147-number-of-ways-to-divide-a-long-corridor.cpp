class Solution {
public:
    int numberOfWays(string s) {
        if(s.size() <= 1) return 0;
        int t = 0;
        for(char ch : s) {
            if(ch == 'S') t++;
        }
        if(t == 0 or t%2==1) return 0;
        int MOD = 1e9 + 7;
        
        long long ans = 1;
        int i = 0;
        int seats = 0;
        while(i < s.size()) {
            if(s[i] == 'S') {
                seats++;
            }
            if(seats == 2) {
                int cnt = 1;
                i++;
                while(i < s.size() and s[i] == 'P') {
                    cnt++;
                    i++;
                }
                if(i == s.size()) break;
                
                ans = (ans*cnt)%MOD;
                i--;
                seats = 0;
            }
            i++;
        }
        
        return ans;
    }
};
class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[100001][3][2][2];
    
    int calc(int n, int i, char prev, bool ab, bool lt) {
        if(i >= n) return 1;
        
        int cnt = 0;
        
        int factor = -1;
        if(prev == 'A') factor = 0;
        else if(prev == 'L') factor = 1;
        else if(prev == 'P') factor = 2;
        
        if(factor != -1 and dp[i][factor][ab][lt] != -1) return dp[i][factor][ab][lt]%MOD;
        
        if(prev == '#') {
            cnt = (cnt%MOD + calc(n, i + 1, 'A', 1, lt)%MOD)%MOD;
            cnt = (cnt%MOD + calc(n, i + 1, 'L', 0, lt)%MOD)%MOD;
            cnt = (cnt%MOD + calc(n, i + 1, 'P', 0, lt)%MOD)%MOD;
        } 
        else if(prev == 'A') {
            cnt = (cnt%MOD + calc(n, i + 1, 'L', ab, 0)%MOD)%MOD;
            cnt = (cnt%MOD + calc(n, i + 1, 'P', ab, 0)%MOD)%MOD;
            
        } else if(prev == 'L') {
            if(ab == false) {
                cnt = (cnt%MOD + calc(n, i + 1, 'A', 1, 0)%MOD)%MOD;
            }
            
            cnt = (cnt%MOD + calc(n, i + 1, 'P', ab, 0)%MOD)%MOD;
            
            if(lt == false) {
                cnt = (cnt%MOD + calc(n, i + 1, 'L', ab, 1)%MOD)%MOD;
            }
        } else {
            if(ab == false) {
                cnt = (cnt%MOD + calc(n, i + 1, 'A', 1, 0)%MOD)%MOD;
            }
            cnt = (cnt%MOD + calc(n, i + 1, 'P', ab, 0)%MOD)%MOD;
            cnt = (cnt%MOD + calc(n, i + 1, 'L', ab, 0)%MOD)%MOD;
        }
        
        if(factor != -1) dp[i][factor][ab][lt] = cnt%MOD;
        return cnt%MOD;
    }
    
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return calc(n, 0, '#', 0, 0);
    }
};
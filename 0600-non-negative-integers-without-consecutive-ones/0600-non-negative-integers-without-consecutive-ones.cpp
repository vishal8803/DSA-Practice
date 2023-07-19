class Solution {
public:
    
    int findIntegers(int n) {
        int f[31];
        f[0] = 1;
        f[1] = 2;
        for(int i = 2; i < 31; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        
        int prevbit = 0;
        int ans = 0;
        int k = 30;
        
        while(k >= 0) {
            if((n>>k)&1) {
                ans += f[k];
                if(prevbit == 1) return ans;
                prevbit = 1;
            } else prevbit = 0;
            k--;
        }
        
        return ans + 1;
    }
};
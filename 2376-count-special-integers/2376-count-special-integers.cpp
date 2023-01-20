class Solution {
public:
    
    int calc(long long num, long long mask, int n) {
        
        if(num > n) {
            return 0;
        }
        
        int count = 1;
        
        for(int i = 0; i <= 9; i++) {
            if(((mask>>i)&1) == 0) {
                long long t = mask | (1<<i);
                count += calc(num*10 + i, t, n);
            } 
        }
        
        return count;
    }
    
    int countSpecialNumbers(int n) {
        vector<long long> v;
        int t = 0;
        for(int i = 1; i <= 9; i++) {
            t += calc(i, (1<<i), n);
        }
        return t;
    }
};
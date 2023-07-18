class Solution {
public:
    int calc(long long n, int a, int b) {
        long long c1 = n/a;
        long long c2 = n/b;
        long long lcm = a*b/__gcd(a,b);
        return c1 + c2 - n/lcm;
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long st = min(a,b);
        long long end = st*n;
        
        int MOD = 1e9 + 7;
        
        while(st <= end) {
            long long mid = (st + end) / 2;
            if(calc(mid, a, b) < n) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return st%MOD;
    }
};
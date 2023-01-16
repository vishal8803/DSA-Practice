class Solution {
public:
    long numZero(long x) {
        long res = 0;

        for (; x > 0; x /= 5) {
            res += x/5;
        }

        return res;
    }
    
    long calc(int K) {
        long l = 0, r =  5L * (K + 1);

        while (l <= r) {
            long m = l + (r - l) / 2;
            long k = numZero(m);

            if (k <= K) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
    
    int preimageSizeFZF(int K) {
        return (int)(calc(K) - calc(K - 1));
    }
};
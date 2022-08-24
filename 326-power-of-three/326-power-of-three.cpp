class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        long long p = 1;
        while(p <= n) {
            if(p==n) return true;
            p=p*3;
        }
        return false;
    }
};
class Solution {
public:
    long long getSum(int n) {
        long long res = ((long long)(n)*(long long)(n+1)) / 2LL;
        return res;
    }
    
    bool isSmaller(int n, int index, int mid, int maxSum) {
        int l = index;
        int r = n - index - 1;
        
        long rs = 0;
        long ls = 0;
        long sum = mid;
        long t = mid - 1;
        if(r <= t) {
            rs = getSum(t) - getSum(t-r);
        } else {
            rs = getSum(t) + r-t;
        }
        
        if(l <= t) {
            ls = getSum(t) - getSum(t-l);
        } else {
            ls = getSum(t) + l-t;
        }
        
        sum += ls + rs;
        
        return sum <= maxSum;
    }
    
    int maxValue(int n, int index, int maxSum) {
        int res;
        int st = 1;
        int end = maxSum;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(isSmaller(n, index, mid, maxSum)) {
                res =  mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
    }
};
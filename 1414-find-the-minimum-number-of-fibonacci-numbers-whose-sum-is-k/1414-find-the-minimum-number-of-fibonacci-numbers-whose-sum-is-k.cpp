class Solution {
public:
    int calc(vector<int> &fibb, int target) {
        int st = 0;
        int end = fibb.size() - 1;
        int res;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(fibb[mid] > target) {
                end = mid - 1;
            } else {
                res = fibb[mid];
                st = mid + 1;
            }
        }
        
        return res;
    }
    int findMinFibonacciNumbers(int k) {
        int prev = 1;
        int curr = 1;
        
        vector<int> fib;
        fib.push_back(1);
        
        while(curr + prev <= k) {
            fib.push_back(curr + prev);
            int t = prev;
            prev = curr;
            curr = curr + t;
        }
        
        int r = 0;
        
        while(k > 0) {
            k -= calc(fib, k);
            r++;
        }
        
        return r;
    }
};
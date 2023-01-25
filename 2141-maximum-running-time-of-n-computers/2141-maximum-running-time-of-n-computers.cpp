class Solution {
public:
    bool isPossible(vector<int> &batteries, int n, long long mid){
        long long total = ((long long)n * mid);  
        
        for(int i : batteries) {
            total -= min((long long)i, mid);
        }
        
        return total <= 0;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long st = 0;
        long long end = 1e14;
        long long res;
        
        while(st <= end) {
            long long mid = (st) + (end - st)/2ll;
            if(isPossible(batteries, n, mid)) {
                res = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
    }
};
class Solution {
public:
    int calc(vector<int> &v, int target) {
        
        int st = 0;
        int end = v.size() - 1;
        int res = -1;
        while(st <= end) {
            int mid = (st + end) / 2;
            if(v[mid] <= target) {
                res = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
    }
    
    int minWastedSpace(vector<int>& p, vector<vector<int>>& boxes) {
        sort(begin(p), end(p));
        
        int n = p.size();
        vector<long long> prefix(n+1);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + p[i];
        }
        
        long long ans = LONG_MAX;
        int MOD = 1e9 + 7;
        
        for(auto box : boxes) {
            sort(begin(box), end(box));
            int idx = calc(p, box[0]);
            int prev = idx;
            long long sum = 0;
            
            if(idx != -1) {
                sum += (long long)box[0]*(long long)(idx + 1) - prefix[idx + 1];
            }
            else {
                prev = -1;
            }
            
            
            
            bool flag = true;
            
            for(int i = 1; i < box.size() and prev < n - 1; i++) {
                int idx = calc(p, box[i]);
                
                if(idx != -1){
                    sum += ((long long)box[i]*(long long)(idx - prev)) - (prefix[idx + 1] - prefix[prev + 1]);
                }
                
                if(idx != -1)
                    prev = idx;
                
            }
            
            if(prev == n - 1){
                ans = min(ans, sum);
            }
            
        }
        
        if(ans == LONG_MAX) return -1;
        
        return ans%MOD;
    }
};
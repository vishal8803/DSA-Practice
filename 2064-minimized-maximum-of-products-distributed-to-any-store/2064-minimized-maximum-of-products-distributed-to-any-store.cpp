class Solution {
public:
    bool isPossible(vector<int> &v, int mx, int n) {
        int shops = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i]%mx==0) shops += v[i]/mx;
            else shops += v[i]/mx + 1;
            
        }
        
        return shops <= n;
    }
    
    int minimizedMaximum(int n, vector<int>& v) {
        int mx = *max_element(v.begin(), v.end());
        
        int st = 1;
        int end = mx;
        int res = -1;
        
        while(st <= end) {
            int mid = (st+end)/2;
            if(isPossible(v, mid, n)) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return res;
    }
};
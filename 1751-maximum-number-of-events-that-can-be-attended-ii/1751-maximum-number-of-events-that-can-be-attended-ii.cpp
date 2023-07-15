class Solution {
public:
    int get(vector<vector<int>> &events, int target) {
        int st = 0;
        int end = events.size() - 1; 
        int res = events.size() + 1;
        while(st <= end) {
            int mid = (st + end) / 2;
            if(events[mid][0] > target) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return res;
    }
    
    int calc(vector<vector<int>> &events, int i, int k, vector<vector<int>> &dp) {
        if(i >= events.size() or k <= 0) return 0;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int res = calc(events, i + 1, k, dp);
        
        int ans = events[i][2];
        int idx = get(events, events[i][1]);
        res = max(res, events[i][2] + calc(events, idx, k - 1, dp));
        
        return dp[i][k] = max(res,ans);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        sort(begin(events), end(events));
        return calc(events, 0, k, dp);
    }
};
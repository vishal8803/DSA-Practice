class Solution {
public:
    int calc(vector<int> &arr, int idx, int k, vector<int> &dp) {
        if(idx==arr.size()) return 0;
        
        int len = 0;
        int mx = INT_MIN;
        int ans = INT_MIN;
        int n = arr.size();
        
        if(dp[idx] != -1) return dp[idx];
        
        for(int j = idx; j < min(n, idx + k); j++) {
            len++;
            mx = max(mx, arr[j]);
            ans = max(ans, mx*len + calc(arr,j+1,k,dp));
        }
        return dp[idx] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return calc(arr,0,k,dp);
    }
};
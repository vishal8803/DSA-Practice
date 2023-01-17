class Solution {
public:
    int calc(vector<int> &arr1, vector<int> &arr2, int left, int idx, vector<unordered_map<int,int>> &dp) {
        if(idx == arr1.size()) return 0;
        if(dp[idx].find(left) != dp[idx].end()) return dp[idx][left];
        
        int res1, res2;
        
        if(arr1[idx] > left) {
            res1 = calc(arr1, arr2, arr1[idx], idx+1, dp);
        } else res1 = INT_MAX;
        
        int pos = upper_bound(arr2.begin(), arr2.end(), left) - arr2.begin();
        if(pos == arr2.size()) res2 = INT_MAX;
        else res2 = calc(arr1, arr2, arr2[pos], idx+1, dp);
        
        if(res2 == INT_MAX) dp[idx][left] = res1;
        else dp[idx][left] = min(res1, res2 + 1);
        
        return dp[idx][left];
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        vector<unordered_map<int,int>> dp(2001);
        sort(arr2.begin(), arr2.end());
        int val = calc(arr1,arr2, INT_MIN, 0, dp);
        if(val == INT_MAX) return -1;
        return val;
    }
};
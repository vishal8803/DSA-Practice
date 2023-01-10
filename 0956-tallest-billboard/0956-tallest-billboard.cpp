class Solution {
public:
    int calc(vector<int> &v, int i, int sum, vector<vector<int>> &dp) {
        if(i == v.size()) {
            if(sum == 0) return 0;
            return INT_MIN;
        }
        
        if(dp[i][sum + 5000] != -1) return dp[i][sum + 5000];
        
        int case1 = v[i] + calc(v, i + 1, sum + v[i], dp);
        int case2 = calc(v, i + 1, sum - v[i], dp);
        int case3 = calc(v, i + 1, sum, dp);
        
        return dp[i][sum + 5000] = max(case1, max(case2, case3));
    }
    
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n,  vector<int>(10005, -1));
        return calc(rods, 0, 0, dp);
    }
};
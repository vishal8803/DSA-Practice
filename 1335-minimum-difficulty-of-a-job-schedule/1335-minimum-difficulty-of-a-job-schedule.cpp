class Solution {
public:
    int dp[301][11];
    
    int calc(vector<int> &v, int i, int d) {
        
        
        if(i == v.size()) {
            if(d != 0) return 1e5;
            return 0;
        } 
        
        if(d == 1) {
            return *max_element(v.begin() + i, v.end());
        }
        
        if(dp[i][d] != -1) return dp[i][d];
        
        int mx = INT_MIN;
        int ans = INT_MAX;
        for(int j = i; j < v.size(); j++) {
            mx = max(mx, v[j]);
            ans = min(ans, mx + calc(v, j + 1, d - 1));
        }
        
        return dp[i][d] = ans;
    }
    
    int minDifficulty(vector<int>& v, int d) {
        memset(dp, -1, sizeof(dp));
        if(v.size() < d) return -1;
        return calc(v, 0, d);
    }
};
class Solution {
public:
    int calc(vector<int> &v, int i,vector<int> &dp) {
        if(i == v.size()) return 0;
        
        if(dp[i] != 1e9) return dp[i];
        
        int sum = v[i] - calc(v, i + 1, dp);
        if(i + 1 < v.size()) {
            sum = max(sum, v[i] + v[i+1] - calc(v, i + 2, dp));
        }
        if(i + 2 < v.size()) {
            sum = max(sum, v[i] + v[i+1] + v[i+2] - calc(v, i + 3, dp));
        }
        
        return dp[i] = sum;
    } 
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, 1e9);
        int t = calc(stoneValue, 0, dp);
        if(t == 0) return "Tie";
        else if(t > 0) return "Alice";
        return "Bob";
    }
};
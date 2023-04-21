class Solution {
public:
    int dp[101][101][101];
    int MOD = 1e9 + 7;
    
    int calc(int i, int people, int totalP, vector<int> &group, vector<int> &profit, int minProfit, int n) {
        
        if(people > n) return 0;
        
        if(i == group.size()) {
            if(people <= n and totalP >= minProfit) return 1;
            return 0;
        }
        
        if(dp[i][people][totalP] != -1) return dp[i][people][totalP];
        
        int total = (calc(i + 1, people + group[i], min(minProfit,totalP + profit[i]), group, profit, minProfit, n)%MOD + calc(i + 1, people, totalP, group, profit, minProfit, n)%MOD)%MOD;
        
        return dp[i][people][totalP] = total;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        
        return calc(0, 0, 0, group, profit, minProfit, n);
    }
};
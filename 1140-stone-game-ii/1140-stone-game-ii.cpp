class Solution {
public:
    int dp[101][101][2];
    int calc(vector<int> &piles, int i, int m, int turn) {
        if(i >= piles.size()) return 0;
        
        if(dp[i][m][turn] != -1) return dp[i][m][turn];
        
        int res = 0;
        int sum = 0;
        if(turn == 0) {
            for(int j = 1; j <= 2*m and i + j <= piles.size(); j++) {
                sum += piles[i+j-1];
                res = max(res, sum + calc(piles, i+j, max(m, j), 1-turn));
            }
        } else {
            res = 1e9;
            for(int j = 1; j <= 2*m and i + j <= piles.size(); j++) {
                res = min(res, calc(piles, i+j, max(m, j), 1-turn));
            }
        }
        
        return dp[i][m][turn] = res;
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return calc(piles, 0, 1, 0);
    }
};
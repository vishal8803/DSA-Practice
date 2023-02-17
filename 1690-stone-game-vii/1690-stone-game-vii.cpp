class Solution {
public:
    int dp[1000][1000][2];
    
    int calc(vector<int> &stones, int i, int j, int sum, int turn) {
        if(i >= j) return 0;
        
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        
        if(turn) {
            int score1 = sum - stones[i];
            int r1 = calc(stones, i + 1, j, score1, 1 - turn) + score1; 
            int score2 = sum - stones[j];
            int r2 = calc(stones, i, j - 1, score2, 1 - turn) + score2;
            return dp[i][j][turn] = max(r1, r2);
        } else {
            int score1 = sum - stones[i];
            int r1 = calc(stones, i + 1, j, score1, 1 - turn) - score1; 
            int score2 = sum - stones[j];
            int r2 = calc(stones, i, j - 1, score2, 1 - turn) - score2;
            return dp[i][j][turn] = min(r1, r2);
        }
        return 0;
    }
    
    int stoneGameVII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for(int i : stones) {
            sum += i;
        }
        return calc(stones, 0, stones.size() - 1, sum, 1);
    }
};
class Solution {
public:
    int dp[101][101][501];
    int calc(vector<vector<char>> &grid, int i, int j, int count, int n, int m) {
        if(i >= n or j >= m or count < 0) return 0;
        
        if(i == n - 1 and j == m - 1) {
            if(grid[i][j] == '(') return 0;
            else count--;
            
            return count == 0;
        }
        
        if(dp[i][j][count] != -1) return dp[i][j][count];
        
        int temp = count;
        
        if(grid[i][j] == '(') count++;
        else count--;
        
        int res = calc(grid, i+1, j, count, n, m);
        res = res | calc(grid, i, j+1, count, n, m);
//         if(count != -1)
//             dp[i][j][count] = res;
        
        return dp[i][j][temp] = res;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return calc(grid, 0, 0, 0, n, m);
    }
};
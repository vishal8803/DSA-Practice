class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int sum = 0;
        
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                int tsum = 0;
                for(int k = 0; k < 3; k++) {
                    tsum += grid[i][j+k] + grid[i+2][j+k];
                }
                tsum += grid[i+1][j+1];
                sum = max(sum, tsum);
            }
        }
        
        return sum;
    }
};
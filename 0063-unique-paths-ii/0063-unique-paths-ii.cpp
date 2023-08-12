class Solution
{
    public:
        int calc(vector<vector < int>> &grid, int i, int j, vector< vector< int>> &dp)
        {
            if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1)
                return 0;

            if (i == grid.size() - 1 && j == grid[0].size() - 1)
            {
                return 1;
            }
            if (dp[i][j] != -1)
                return dp[i][j];

            return dp[i][j] = calc(grid, i + 1, j, dp) + calc(grid, i, j + 1, dp);
        }

    int uniquePathsWithObstacles(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector < int>> dp(n, vector<int> (m, -1));
        return calc(grid, 0, 0, dp);
    }
};
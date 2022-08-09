class Solution
{
    public:
        int dp[71][5001];
        int calc(vector<vector < int>> &mat, int i, int target, int sum)
        {
            if (i == mat.size())
            {
                return abs(sum - target);
            }

            if (dp[i][sum] != -1) return dp[i][sum];

            int mn = INT_MAX;
            for (int j = 0; j < mat[0].size(); j++)
            {
                mn = min(mn, calc(mat, i + 1, target, sum + mat[i][j]));
                if (mn == 0) break;
            }

            return dp[i][sum] = mn;
        }

    int minimizeTheDifference(vector<vector < int>> &mat, int target)
    {
        int ans = INT_MAX;
        memset(dp, -1, sizeof(dp));
        return calc(mat, 0, target, 0);
    }
};
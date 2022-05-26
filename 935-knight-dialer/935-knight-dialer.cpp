class Solution
{
    long long int mod=1e9+7;
public:
    int knightDialer(int n)
    {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(10, 0));
        dp[1] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (long long int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][4] + dp[i - 1][6])%(mod);
            dp[i][1] = (dp[i - 1][8] + dp[i - 1][6])%(mod);
            dp[i][2] = (dp[i - 1][9] + dp[i - 1][7])%(mod);
            dp[i][3] = (dp[i - 1][4] + dp[i - 1][8])%(mod);
            dp[i][4] = (dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0])%(mod);
            dp[i][5] = 0;
            dp[i][6] = (dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][0])%(mod);
            dp[i][7] = (dp[i - 1][2] + dp[i - 1][6])%(mod);
            dp[i][8] = (dp[i - 1][1] + dp[i - 1][3])%(mod);
            dp[i][9] = (dp[i - 1][4] + dp[i - 1][2])%(mod);
        }
        long long int ans = 0;
        for (long long int i = 0; i < 10; i++){
            ans = (ans + dp[n][i])%mod;
        }
        return int(ans);
    }
};
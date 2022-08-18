class Solution
{
    public:
        long long appealSum(string s)
        {
            int n = s.length();
            vector<int> dp(n), prev(26, -1);

            long long count = 1;
            dp[0] = 1;
            prev[s[0]-'a'] = 0;

            for (int i = 1; i < s.length(); i++)
            {
                dp[i] = dp[i - 1] + i - prev[s[i] - 'a'];
                prev[s[i] - 'a'] = i;
                count += dp[i];
            }

            return count;
        }
};
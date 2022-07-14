class Solution
{
    public:
        double calc(vector<int> &prefix, int i, int k, int n, vector<vector< double>> &dp)
        {
            if (i == n)
                return 0;

            if (k == 1)
            {
                if (i == 0)
                {
                    double ans = (double)(prefix[n - 1]) / (n);
                    return ans;
                }

                double diff = prefix[n - 1] - prefix[i - 1];
                double ans = (double)(diff) / (n - i);
                return ans;
            }

            if (k > n - i + 1)
            {
                if (i == 0)
                    return (double) prefix[n - 1];

                return (double) prefix[n - 1] - (double) prefix[i - 1];
            }

            if (dp[i][k] != -1)
                return dp[i][k];

            double ans = DBL_MIN;

            for (int j = i; j < n; j++)
            {

                double temp = (double)(prefix[j] - (i != 0 ? prefix[i - 1] : 0)) / (j - i + 1) + calc(prefix, j + 1, k - 1, n, dp);
                ans = max(ans, temp);
            }

            return dp[i][k] = ans;
        }

    double largestSumOfAverages(vector<int> &nums, int k)
    {
        vector<int> prefix(nums.size(), 0);

        vector<vector < double>> dp(nums.size() + 1, vector<double> (k + 1, -1));

        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        return calc(prefix, 0, k, nums.size(), dp);
    }
};
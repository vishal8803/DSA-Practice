class Solution
{
    public:
        int calc(vector<int> &boxes, int streak, vector<vector< vector< int>>> &dp, int left, int right)
        {
            if (left > right) return 0;
            if (left == right) return (streak + 1) *(streak + 1);
            if (dp[left][right][streak] != -1) return dp[left][right][streak];

            int mx = (streak + 1) *(streak + 1) + calc(boxes, 0, dp, left + 1, right);

            for (int i = left + 1; i <= right; i++)
            {
                if (boxes[left] == boxes[i])
                {
                    mx = max(mx, calc(boxes, 0, dp, left + 1, i - 1) + calc(boxes, streak + 1, dp, i, right));
                }
            }

            dp[left][right][streak] = mx;
            return mx;
        }

    int removeBoxes(vector<int> &boxes)
    {
        int n = boxes.size();
        vector<vector<vector< int>>> dp(n, vector<vector < int>> (n, vector<int> (n, -1)));
        return calc(boxes, 0, dp, 0, n - 1);
    }
};
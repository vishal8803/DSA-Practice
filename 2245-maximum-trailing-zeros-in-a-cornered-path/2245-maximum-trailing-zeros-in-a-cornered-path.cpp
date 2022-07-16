class Solution
{
    public:
        int num2(int num)
        {
            int count = 0;
            while (true)
            {
                if (num % 2 == 0)
                {
                    num /= 2;
                    count++;
                }
                else
                {
                    break;
                }
            }
            return count;
        }

    int num5(int num)
    {
        int count = 0;
        while (true)
        {
            if (num % 5 == 0)
            {
                num /= 5;
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }

    int maxTrailingZeros(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<int, int>>> up(n, vector<pair<int, int>> (m));
        vector<vector<pair<int, int>>> down(n, vector<pair<int, int>> (m));
        vector<vector<pair<int, int>>> left(n, vector<pair<int, int>> (m));
        vector<vector<pair<int, int>>> right(n, vector<pair<int, int>> (m));

        for (int i = 0; i < n; i++)
        {
            int two = 0;
            int five = 0;
            for (int j = 0; j < m; j++)
            {
                two += num2(grid[i][j]);
                five += num5(grid[i][j]);
                left[i][j] = { two,
                    five
                };
            }
        }

        for (int i = 0; i < n; i++)
        {
            int two = 0;
            int five = 0;
            for (int j = m - 1; j >= 0; j--)
            {
                two += num2(grid[i][j]);
                five += num5(grid[i][j]);
                right[i][j] = { two,
                    five
                };
            }
        }

        for (int j = 0; j < m; j++)
        {
            int two = 0;
            int five = 0;
            for (int i = 0; i < n; i++)
            {
                two += num2(grid[i][j]);
                five += num5(grid[i][j]);
                up[i][j] = { two,
                    five
                };
            }
        }

        for (int j = 0; j < m; j++)
        {
            int two = 0;
            int five = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                two += num2(grid[i][j]);
                five += num5(grid[i][j]);
                down[i][j] = { two,
                    five
                };
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int u = min(up[i][j].first, up[i][j].second);
                int d = min(down[i][j].first, down[i][j].second);
                int l = min(left[i][j].first, left[i][j].second);
                int r = min(right[i][j].first, right[i][j].second);
                
                ans = max(ans, max(max(u,d), max(l,r)));
                
                if (i + 1 < n && j + 1 < m)
                {
                    int totalTwos = right[i][j + 1].first + down[i + 1][j].first + num2(grid[i][j]);
                    int totalFives = right[i][j + 1].second + down[i + 1][j].second + num5(grid[i][j]);
                    ans = max(ans, min(totalTwos, totalFives));
                }
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    int totalTwos = left[i][j - 1].first + up[i - 1][j].first + num2(grid[i][j]);
                    int totalFives = left[i][j - 1].second + up[i - 1][j].second + num5(grid[i][j]);
                    ans = max(ans, min(totalTwos, totalFives));
                }
                if (i - 1 >= 0 && j + 1 < m)
                {
                    int totalTwos = up[i - 1][j].first + right[i][j + 1].first + num2(grid[i][j]);
                    int totalFives = up[i - 1][j].second + right[i][j + 1].second + num5(grid[i][j]);
                    ans = max(ans, min(totalTwos, totalFives));
                }
                if (i + 1 < n && j - 1 >= 0)
                {
                    int totalTwos = down[i + 1][j].first + left[i][j - 1].first + num2(grid[i][j]);
                    int totalFives = down[i + 1][j].second + left[i][j - 1].second + num5(grid[i][j]);
                    ans = max(ans, min(totalTwos, totalFives));
                }
            }
        }

        return ans;
    }
};
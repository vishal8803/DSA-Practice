class Solution
{
    public:
        vector<int> goodDaysToRobBank(vector<int> &security, int time)
        {
            int n = security.size();

            vector<int> left(n);
            vector<int> right(n);

            left[0] = 1;
            right[n - 1] = 1;

            for (int i = 1; i < security.size(); i++)
            {
                if (security[i] <= security[i - 1])
                {
                    left[i] = 1 + left[i - 1];
                }
                else
                {
                    left[i] = 1;
                }
            }

            for (int i = n - 2; i >= 0; i--)
            {
                if (security[i] <= security[i + 1])
                {
                    right[i] = 1 + right[i + 1];
                }
                else
                {
                    right[i] = 1;
                }
            }

            vector<int> ans;

            for (int i = time; i < n - time; i++)
            {
                if (left[i] >= time+1 && right[i] >= time+1)
                {
                    ans.push_back(i);
                }
            }

            return ans;
        }
};
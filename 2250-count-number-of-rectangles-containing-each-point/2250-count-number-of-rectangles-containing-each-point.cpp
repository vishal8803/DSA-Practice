class Solution
{
    public:
        int calc(vector<int> &a, int target)
        {
            int st = 0;
            int end = a.size();

            while (st < end)
            {
                int mid = (st + end) / 2;
                if (a[mid] >= target)
                {
                    end = mid;
                }
                else
                {
                    st = mid + 1;
                }
            }

            return st;
        }

    vector<int> countRectangles(vector<vector < int>> &rectangles, vector< vector< int>> &points)
    {
        vector<vector < int>> mp(101);

        for (vector<int> rectangle: rectangles)
        {
            mp[rectangle[1]].push_back(rectangle[0]);
        }

        for (auto &it: mp)
        {
            sort(it.begin(), it.end());
        }

        vector<int> ans;

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int count = 0;

            for (int j = y; j <= 100; j++)
            {
                count += mp[j].size() - calc(mp[j], x);
            }

            ans.push_back(count);
        }

        return ans;
    }
};
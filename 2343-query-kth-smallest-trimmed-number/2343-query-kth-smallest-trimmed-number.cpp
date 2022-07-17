class Solution
{
    public:
        string trim(string s, int k)
        {
            int len = s.length();
            if (len == k)
                return s;

            return s.substr(len - k);
        }

    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector< int>> &queries)
    {

        vector<int> ans;

        for (auto q: queries)
        {
            int k = q[0];
            int t = q[1];

            priority_queue<pair<string, int>> pq;

            for (int i = 0; i < nums.size(); i++)
            {
                pq.push({trim(nums[i], t),i});
                if (pq.size() > k)
                    pq.pop();
            }

            ans.push_back(pq.top().second);
        }

        return ans;
    }
};
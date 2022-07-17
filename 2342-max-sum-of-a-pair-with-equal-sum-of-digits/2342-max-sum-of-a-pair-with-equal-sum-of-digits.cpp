class Solution
{
    public:
        int digitSum(int num)
        {
            int sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }

    int maximumSum(vector<int> &nums)
    {
        map<int, vector < int>> mp;

        for (auto it: nums)
        {
            mp[digitSum(it)].push_back(it);
        }

        for (auto &it: mp)
        {
            sort(it.second.begin(), it.second.end());
        }

        int ans = -1;

        for (auto it: mp)
        {
            vector<int> temp = it.second;
            if (temp.size() >= 2)
            {
                int n = temp.size();
                ans = max(ans, temp[n - 1] + temp[n - 2]);
            }
        }

        return ans;
    }
};
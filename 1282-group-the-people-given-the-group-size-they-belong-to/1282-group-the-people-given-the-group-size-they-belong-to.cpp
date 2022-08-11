class Solution
{
    public:
        vector<vector < int>> groupThePeople(vector<int> &groupSizes)
        {
            map<int, vector < int>> mp;

            for (int i = 0; i < groupSizes.size(); i++)
            {
                mp[groupSizes[i]].push_back(i);
            }

            vector<vector < int>> ans;

            for (auto it: mp)
            {
                int size = it.first;
                vector<int> t = it.second;

                vector<int> rt;

                int count = 0;
                for (int i: t)
                {
                    count++;
                    rt.push_back(i);
                    if (count == size)
                    {
                        ans.push_back(rt);
                        count = 0;
                        rt = vector<int>();
                    }
                }
            }

            return ans;
        }
};
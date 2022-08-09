class RangeFreqQuery
{
    public:
        vector<int> mp[10001] = {};

    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        return upper_bound(begin(mp[value]), end(mp[value]), right) - lower_bound(begin(mp[value]), end(mp[value]), left);
    }
};

/**
 *Your RangeFreqQuery object will be instantiated and called as such:
 *RangeFreqQuery* obj = new RangeFreqQuery(arr);
 *int param_1 = obj->query(left,right,value);
 */
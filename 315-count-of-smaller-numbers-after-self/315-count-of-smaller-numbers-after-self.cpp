class Solution
{
    public:
        void merge(vector<pair<int, int>> &nums, int st, int mid, int end, vector< int > &cnt)
        {

            int i = st, j = mid + 1, k = 0;
            vector<pair<int, int>> temp(end - st + 1);

            while (i <= mid && j <= end)
            {
                if (nums[i].first <= nums[j].first)
                {
                    temp[k++] = nums[j++];
                }
                else
                {
                    cnt[nums[i].second] += end - j + 1;
                    temp[k++] = nums[i++];
                }
            }

            while (i <= mid)
            {
                temp[k++] = nums[i++];
            }

            while (j <= end)
            {
                temp[k++] = nums[j++];
            }

            for (int i = st; i <= end; i++)
            {
                nums[i] = temp[i - st];
            }
        }
    void mergeSort(vector<pair<int, int>> &nums, int st, int end, vector< int > &cnt)
    {
        if (st < end)
        {
            int mid = (st + end) / 2;
            mergeSort(nums, st, mid, cnt);
            mergeSort(nums, mid + 1, end, cnt);
            merge(nums, st, mid, end, cnt);
        }
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> cnt(nums.size(), 0);

        vector<pair<int, int>> t2;

        for (int i = 0; i < nums.size(); i++)
        {
            t2.push_back({ nums[i],
                i });
        }
        mergeSort(t2, 0, nums.size() - 1, cnt);

        return cnt;
    }
};
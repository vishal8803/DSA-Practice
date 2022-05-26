class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int p = INT_MIN;

            int temp = 1;

            for (int i: nums)
            {
                temp = temp * i;
                p = max(p, temp);

                if (i == 0)
                {
                    temp = 1;
                }
            }

            reverse(nums.begin(), nums.end());

            temp = 1;

            for (int i: nums)
            {
                temp = temp * i;
                p = max(p, temp);

                if (i == 0)
                {
                    temp = 1;
                }
            }

            return p;
        }
};
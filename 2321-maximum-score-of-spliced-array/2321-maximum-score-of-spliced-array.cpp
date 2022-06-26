class Solution
{
    public:
        int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
        {
            int sum1 = 0;
            int sum2 = 0;
            int ans = 0;

            for (int i: nums1)
            {
                sum1 += i;
            }

            for (int i: nums2)
            {
                sum2 += i;
            }

            ans = max(sum1, sum2);
            int curr = 0;
            int mx = 0;
            for (int i = 0; i < nums1.size(); i++)
            {
                curr += nums2[i] - nums1[i];
                mx = max(mx, curr);
                if (curr < 0)
                    curr = 0;
            }

            ans = max(ans, sum1 + mx);
            curr = 0;
            mx = 0;
            for (int i = 0; i < nums1.size(); i++)
            {
                curr += nums1[i] - nums2[i];
                mx = max(mx, curr);
                if (curr < 0)
                    curr = 0;
            }
            ans = max(ans, sum2 + mx);
            return ans;
        }
};
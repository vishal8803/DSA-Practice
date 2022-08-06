class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k)
        {
            map<int, int> mp;
            int i = 0;
            int j = 0;

            while (j < nums.size() && j <= k)
            {
                if (mp.find(nums[j]) != mp.end()) return true;
                mp[nums[j]]++;
                j++;
            }

            while (j < nums.size())
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
                if (mp.find(nums[j]) != mp.end()) return true;
                mp[nums[j]]++;
                j++;
            }

            return false;
        }
};
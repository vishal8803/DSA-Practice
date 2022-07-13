class Solution
{
    public:
        bool calc(int i, vector<bool> &visited, vector<int> &nums, int curr, int sum, int k)
        {
            if(k==0) return true;
            if(curr > sum) return false;
            if(curr == sum) return calc(0, visited, nums, 0, sum, k-1);
            
            for(int j = i; j < nums.size(); j++){
                if(visited[j]) continue;
                visited[j] = true;
                if(calc(j+1,visited, nums, curr + nums[j], sum, k)) return true;
                visited[j] = false;
            }
            return false;
        }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int i: nums)
        {
            sum += i;
        }

        if (sum % k != 0)
            return false;

        
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> temp(nums.size(),false);
        for (int i: nums)
        {
            if (i > sum / k)
                return false;
        }

        return calc(0, temp, nums, 0, sum/k, k);
    }
};
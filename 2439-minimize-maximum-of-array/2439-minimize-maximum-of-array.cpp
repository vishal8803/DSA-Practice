class Solution {
public:
    bool isPossible(vector<int> &nums, int t) {
        long long inc = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] <= t) {
                inc -= min((long long)t-(long long)nums[i], inc);
            } else inc += nums[i] - t;
        }
        return inc <= 0;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int st = 0;
        int end = 1e9;
        int res = -1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(isPossible(nums, mid)) {
                res = mid;
                end = mid - 1;
            } else st = mid + 1;
        }
        return res;
    }
};
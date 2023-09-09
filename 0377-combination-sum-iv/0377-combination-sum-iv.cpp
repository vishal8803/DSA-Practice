class Solution {
public:
    int calc(vector<int> &nums, int target, vector<int> &dp) {
        if(target==0) return 1;
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt += calc(nums,target-nums[i],dp);
        }
        return dp[target] = cnt;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        int cnt = calc(nums,target,dp);
        return cnt;
    }
};
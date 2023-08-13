class Solution {
public:
    bool calc(vector<int> &nums, int i,vector<int>& dp) {
        if(i==nums.size()) return true;
        
        if(dp[i] != -1) return dp[i];
        
        if(i+1 < nums.size() && nums[i]==nums[i+1] && calc(nums,i+2,dp)) return dp[i] = true;
        if(i+2 < nums.size() && nums[i]==nums[i+1] && nums[i+1]==nums[i+2] && calc(nums,i+3,dp)) return dp[i] = true;
        if(i+2 < nums.size() && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1 && calc(nums,i+3,dp)) return dp[i] = true;
        
        return dp[i] = false;
    }
    
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return calc(nums,0,dp);
    }
};
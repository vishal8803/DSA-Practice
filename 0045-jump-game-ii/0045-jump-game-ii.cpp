class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()];
        int n = nums.size();
        dp[n-1]=0;
        for(int i=n-2; i>=0; i--){
            int mn=INT_MAX-1;
            for(int j=1; j<=nums[i] && i+j<n; j++){
                mn=min(mn,dp[i+j]);
            }
            dp[i]=1+mn;
        }
        return dp[0];
    }
};
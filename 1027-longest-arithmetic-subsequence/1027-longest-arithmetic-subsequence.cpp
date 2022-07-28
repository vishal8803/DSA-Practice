class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        int mx = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int newValue = dp[j][diff] + 1;
                dp[i][diff] = newValue;
                mx = max(mx, newValue);
            }
        }
        
        return mx + 1;
    }
};
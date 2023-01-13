class Solution {
public:
    int calc(vector<int> &nums, int n, int mask, int chance, vector<vector<int>> &dp) {
        if(chance == n + 1) {
            return 0;
        }
        
        int score = 0;
        
        if(dp[chance][mask] != -1) return dp[chance][mask];
        
        for(int i = 0; i < 2*n; i++) {
            if(((mask>>i)&1) == 1) continue;
            for(int j = i + 1; j < 2*n; j++) {
                if(((mask>>j)&1) == 0) {
                    
                    int nmask = (mask)|(1<<i);
                    nmask = (nmask)|(1<<j);
                    
                    int temp = chance*(__gcd(nums[i], nums[j]));
                    
                    score = max(score, temp + calc(nums, n, nmask, chance + 1, dp));
                }
            }
        }
        
        return dp[chance][mask] = score;
    }
    
    int maxScore(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>((1<<n+1), -1));
        return calc(nums, n/2, 0, 1, dp);
    }
};
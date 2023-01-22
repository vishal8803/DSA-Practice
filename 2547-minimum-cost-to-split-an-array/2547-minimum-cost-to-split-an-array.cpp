class Solution {
public:
    int calc(vector<int> &nums, int i, int k, int n, vector<int> &dp) {
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        vector<bool> freq(n, 0), erased(n,0);
        
        int count = 0;
        int ans = INT_MAX;
        
        for(int j = i; j < n; j++) {
            
            if(freq[nums[j]] == 1) {freq[nums[j]] = 0; count--; erased[nums[j]] = 1;}
            else if(erased[nums[j]] == 0) {freq[nums[j]] = 1; count++;}
            
            int size = count;
            int val = k + (j-i+1)-size + calc(nums, j + 1, k, n, dp);
            ans = min(ans, val);
        }
        
        return dp[i] = ans;
    }
    
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int t = calc(nums, 0, k, n, dp);
        return t;
    }
};
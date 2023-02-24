class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i : nums) sum += i;
        
        vector<int> dp(sum + 1, 0);
        
        dp[nums[0]] = 2;
        
        for(int i = 1; i < n; i++) {
            for(int j = sum -nums[i]; j >= 0; j--) {
                if(dp[j]) {
                    dp[j+nums[i]] |= (dp[j]<<1);
                }
            }
            dp[nums[i]]|=2;
        }
        
        
        for(int len = 1; len <= n - 1; len++) {
            int temp = (sum*len)/n;
            
            if((sum*len)%n == 0 and (1<<len & dp[(sum*len)/n])) {
                return true;
            }
        }
        
        return false;
    }
};
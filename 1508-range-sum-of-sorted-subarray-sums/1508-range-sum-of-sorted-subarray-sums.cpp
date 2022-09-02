class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sums;
        int MOD = 1000000007;
        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                sum %= MOD;
                sums.push_back(sum);
            }
        }
        
        sort(sums.begin(), sums.end());
        long long ans = 0;
        
        for(int i = left-1; i<= right-1; i++) {
            ans += sums[i];
            ans %= MOD;
        }
        
        return ans;
    }
};
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        long long cnt = 0;
        for(int i = 0; i <= n/2; i++) {
            if(nums[i] > k) {
                cnt += nums[i]-k;
            }
        }
        for(int i = n/2; i < n; i++) {
            if(nums[i] < k) {
                cnt += k - nums[i];
            }
        }
        return cnt;
    }
};
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        int prev = nums[n-1];
        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= nums[i+1]) {
                continue;
            } else {
                long long ele = ceil((nums[i] + nums[i+1] - 1ll)/(nums[i+1]));
                count += ele - 1;
                nums[i] = nums[i]/ele;
            }
        }
        return count;
    }
};
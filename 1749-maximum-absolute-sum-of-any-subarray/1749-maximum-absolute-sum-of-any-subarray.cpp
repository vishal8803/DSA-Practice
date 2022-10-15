class Solution {
public:
    int maxSum(vector<int> &nums) {
        int cs = 0;
        int sum = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            cs += nums[i];
            sum = max(sum, cs);
            if(cs < 0) cs = 0;
            nums[i] = -nums[i];
        }
        
        return sum;
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = maxSum(nums);
        return max(sum, maxSum(nums));
    }
};
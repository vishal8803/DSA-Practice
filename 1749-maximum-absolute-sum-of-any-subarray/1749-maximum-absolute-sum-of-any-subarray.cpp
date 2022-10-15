class Solution {
public:
    int maxSum(vector<int> &nums) {
        int cs = 0;
        int sum = nums[0];
        
        for(int i : nums) {
            cs += i;
            sum = max(sum, cs);
            if(cs < 0) cs = 0;
        }
        
        return sum;
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = maxSum(nums);
        
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = -nums[i];
        }
        
        return max(sum, maxSum(nums));
        
    }
};
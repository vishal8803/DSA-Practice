class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int p1 = nums[n-1] * nums[n-2];
        int p2 = nums[0] * nums[1];
        
        return p1 - p2;
    }
};
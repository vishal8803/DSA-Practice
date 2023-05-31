class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 and k > 0) {
                nums[i] = -1*nums[i];
                k--;
            }
        }
        
        sort(nums.begin(), nums.end());
        if(k%2 == 1) {
            nums[0] = -nums[0];
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
        return sum;
    }
};
class Solution {
public:
    int calcMinimum(vector<int> nums, int bit) {
        int count = 0;
        
        if(bit) {
            for(int i = 1; i < nums.size(); i+=2) {
                if(i == nums.size() - 1) {
                    if(nums[i] <= nums[i-1]) {
                        count += abs(nums[i] - nums[i-1]) + 1;
                    }
                } else {
                    if(nums[i-1] >= nums[i]) {
                        int diff= abs(nums[i] - nums[i-1]) + 1;
                        count += diff;
                        nums[i-1] -= diff;
                    }
                    if(nums[i+1] >= nums[i]) {
                        int diff= abs(nums[i] - nums[i+1]) + 1;
                        count += diff;
                        nums[i+1] -= diff;
                    }
                }
            }
        } else {
            for(int i = 0; i < nums.size(); i+=2) {
                if(i == 0) {
                    if(nums[i] <= nums[i+1]) {
                        int diff= abs(nums[i+1] - nums[i]) + 1;
                        count += diff;
                        nums[i+1] -= diff;
                    }
                } else if(i == nums.size() - 1) {
                    if(nums[i] <= nums[i-1]) {
                        int diff = abs(nums[i] - nums[i-1]) + 1;
                        count += diff;
                        nums[i-1] -= diff;
                    }
                } else {
                    if(nums[i-1] >= nums[i]) {
                        int diff= abs(nums[i] - nums[i-1]) + 1;
                        count += diff;
                        nums[i-1] -= diff;
                    }
                    if(nums[i+1] >= nums[i]) {
                        int diff= abs(nums[i] - nums[i+1]) + 1;
                        count += diff;
                        nums[i+1] -= diff;
                    }
                }
            }
        }
        
        return count;
    }
    
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size()==1) return 0;
        
        return min(calcMinimum(nums,0),calcMinimum(nums,1));
    }
};
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] > nums[i]){
                if(i<2 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];

                count++;

                if(count>1)
                    return false;
            }
        }
        
        return true;
    }
};
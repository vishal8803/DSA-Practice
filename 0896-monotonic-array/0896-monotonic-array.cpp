class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false;
        bool dec = false;
        
        for(int i = 0; i< nums.size()-1; i++){
            if(nums[i]>nums[i+1])
            {
                dec = true;
            }
            if(nums[i]<nums[i+1])
            {
                inc = true;
            }
            if(nums[i]==nums[i+1])
            {
                continue;
            }
        }
        
        if(inc && dec)
            return false;
        
        return true;
    }
};
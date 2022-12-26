class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        
        int idx = nums[0];
        if(nums[0]==0)
            return false;
        for(int i = 1; i < nums.size(); i++){
            
            if(idx>=nums.size()-1)
                return true;
            
            if(nums[i]==0 && i>=idx)
                return false;
            
            idx = max(idx,i+nums[i]);
            
        }
        return false;
    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        
        int i = 0;
        
        for(int k=0; k<nums.size(); k++){
            if(nums[k]&1){
                
            }else{
                swap(nums[k],nums[i]);
                i++;
            }
        }
        return nums;
    }
};
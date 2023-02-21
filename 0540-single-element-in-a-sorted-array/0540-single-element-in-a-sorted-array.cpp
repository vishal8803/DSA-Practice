class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0] ;
        int st =0 ;
        int end = nums.size() ;
        while(st<=end)
        {
            int mid = (st+end)/2 ;
            if(nums[mid]==nums[mid^1])
            {
                  st = mid + 1 ; 
            }else
            {
                end = mid -1 ;
            }
        }
        return nums[st] ;
    }
};
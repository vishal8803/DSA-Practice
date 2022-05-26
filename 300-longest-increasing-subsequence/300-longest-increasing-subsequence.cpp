class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        int size = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(lis[size-1] < nums[i]){
                lis.push_back(nums[i]);
                size++;
            }else{
                int idx = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                lis[idx] = nums[i];
            }
        }
        return lis.size();
    }
};
class Solution {
public:
     int maxSubArray(vector<int>& nums) {
        int s=nums[0],cs=0;
        for(int i=0; i<nums.size(); i++){
            cs=cs+nums[i];
            s=max(s,cs);
            if(cs<0)
            {
                cs=0;
            }
        }
        return s;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int s1 = maxSubArray(nums);
        int s=0;
        int isAll = 0;
        for(int i=0;i<nums.size(); i++){
            s=s+nums[i];
            if(nums[i]<0)
            {
                isAll++;
            }
            nums[i]=-nums[i];
        }
        if(isAll==nums.size())
            return s1;
        int s2 = s+maxSubArray(nums);
        // cout<<s1<<" "<<s2<<endl;
        return max(s2,s1);
    }
};
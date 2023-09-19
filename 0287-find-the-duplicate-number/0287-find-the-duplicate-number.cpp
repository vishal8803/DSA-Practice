class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int count = 0;
        
        while(i<nums.size())
        {
            int t = nums[i];
            count = 0;
            while(i<nums.size() && nums[i]==t){
                count++;
                i++;
                if(count>1)
                    return t;
            }
        }
        return -1;
    }
};
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0;
        while(i<nums.size()){
            int count = 0;
            while(i<nums.size() && nums[i]==0){
                count++;
                i++;
            }
            ans += ((long long)(count)*(long long)(count+1))/2;
            i++;
        }
        return ans;
    }
};
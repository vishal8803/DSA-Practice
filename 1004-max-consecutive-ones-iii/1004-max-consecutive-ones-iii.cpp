class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int zero = 0;
        
        while(j < nums.size()) {
            if(nums[j]==0) zero++;
            if(zero <= k){
                ans = max(ans, j-i+1);
                j++;
            }else if(zero > k){
                while(i<=j && zero > k){
                    if(nums[i]==0)zero--;
                    i++;
                }
                ans = max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};
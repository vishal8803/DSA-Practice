class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<long long,long long>> dp(nums.size());
        
        int ans =0 ;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                long long diff =((long long)nums[i]-(long long)nums[j]);
                if(dp[j].find(diff)!=dp[j].end()){
                    ans += dp[j][diff];
                    dp[i][diff]+=1+dp[j][diff];
                }else{
                    dp[i][diff]++;
                }
            }
        }
        return ans;
    }
};
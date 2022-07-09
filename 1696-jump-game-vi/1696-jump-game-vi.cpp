class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        map<int,int> mp;
        
        int n = nums.size();
        vector<int> dp(n);
        int j = n-1;
        int i = n-1;
        
        dp[j] = nums[j];
        mp[dp[j]]++;
        j--;
        
        while(j>=0){
            
            int elem = mp.rbegin()->first;
            dp[j] = nums[j] + elem;
            mp[dp[j]]++;
            
            if(i-j+1 > k){
                mp[dp[i]]--;
                if(mp[dp[i]]==0)
                    mp.erase(dp[i]);
                i--;
            }
            j--;
        }
        return dp[0];
    }
};
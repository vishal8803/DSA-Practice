class Solution {
public:
    int calc(vector<int>& coins, int target, int i, vector<vector<int>>& dp){
        if(target==0){
            return 0;
        }
        if(i==coins.size() || target<0)
            return 100000;
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
            
        
        return dp[i][target] = min(1+calc(coins,target-coins[i],i,dp),calc(coins,target,i+1,dp));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int mn = calc(coins,amount,0,dp);
        
        if(mn==100000)
            return -1;
        
        return mn;
    }
};
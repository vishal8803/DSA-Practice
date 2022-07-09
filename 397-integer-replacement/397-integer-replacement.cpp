class Solution {
public:
    int count(int n, map<int,int> &dp){
        if(n==1)
            return 0;
        
        if(dp[n] != 0)
            return dp[n];
        
        if(n%2==0){
            return dp[n] = 1 + count(n/2,dp);
        }
        
        return dp[n] = 2 + min(count(n/2,dp), count(n/2 + 1,dp));
    }
    
    int integerReplacement(int n) {
        map<int,int> dp;
        return count(n,dp);
    }
};
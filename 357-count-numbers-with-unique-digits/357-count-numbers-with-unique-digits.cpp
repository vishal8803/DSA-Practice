class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        
        if(n==1)
            return 10;
        
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 10;
        dp[2] = 91;
        int p = 81;
        int num = 8;
        
        for(int i = 3; i<=n; i++){
            p = p*num;
            num--;
            dp[i] =  dp[i-1] + p;
        }
        return dp[n];
    }
};
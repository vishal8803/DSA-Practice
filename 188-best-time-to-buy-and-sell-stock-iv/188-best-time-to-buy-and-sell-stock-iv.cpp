class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0 || k==0)
            return 0;
        int dp[k+1][n];
        for(int i=0; i<=k; i++){
            dp[i][0]=0;
        }
        
        for(int j=0; j<n; j++){
            dp[0][j]=0;
        }
        
        for(int i=1; i<k+1; i++){
            int mx = INT_MIN;
            for(int j=1; j<n; j++){
                int t = dp[i-1][j-1]-prices[j-1];
                mx=max(mx,t);
                dp[i][j]=max(dp[i][j-1],mx+prices[j]);
            }
        }
        return dp[k][n-1];
    }
};
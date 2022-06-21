class Solution {
public:
    int calc(vector<int> &coin, int target){
        int n = coin.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1));
        
        for(int j=0; j<target+1; j++)
            dp[0][j]=INT_MAX-1;
    
        for(int i=1; i<n+1; i++)
            dp[i][0]=0;

        for(int j=1; j<target+1; j++)
        {
            if(coin[0] != 0 && j%coin[0]==0)
                dp[1][j]=j/coin[0];
            else
                dp[1][j]=INT_MAX-1;
        }

        for(int i=2; i<n+1; i++)
        {
            for(int j=1; j<target+1; j++)
            {
                if(coin[i-1]<=j)
                {
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coin[i-1]]);
                }else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int ans = dp[n][target];
        
        if(ans==INT_MAX || ans == INT_MAX-1)
            return -1;
        
        return ans;
    }
    
    int minimumNumbers(int num, int k) {
        if(num==0)
            return 0;
        
        vector<int> search;
        
        for(int i = k; i<=num; i+=10){
            search.push_back(i);
        }
        if(search.size()==0)
            return -1;
        
        
        
        return calc(search,num);
    }
};
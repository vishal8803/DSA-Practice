class Solution
{
    public:
        int dp[101][21][101];

        int calc(vector<int> &houses, vector<vector< int >> &cost, int i, int m, int n, int target, int prevCol, int nbr)
        {
            if(nbr > target) return INT_MAX/2;
            
            if (i == houses.size())
            {
                if (nbr == target)
                {
                    return 0;
                }
                return INT_MAX/2;
            }
            
            if(dp[i][prevCol][nbr] != -1) return dp[i][prevCol][nbr];
            
            int ans = INT_MAX/2;
            if (houses[i] != 0)
            {
                ans = min(ans, calc(houses,cost,i+1,m,n,target,houses[i],(houses[i]==prevCol?nbr:nbr+1)));
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    ans = min(ans, cost[i][j] + calc(houses,cost,i+1,m,n,target,j+1,(prevCol==j+1?nbr:nbr+1)));
                }
            }
            return dp[i][prevCol][nbr] = ans;
        }

    int minCost(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target)
    {
        memset(dp,-1,sizeof(dp));
        int ans = calc(houses,cost,0,m,n,target,0,0);
        return ans==INT_MAX/2 ? -1 : ans;
    }
};
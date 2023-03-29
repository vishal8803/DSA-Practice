class Solution {
public:
    int calc(vector<int>& v, int i, int count, vector<vector<int>> &dp){
        if(i==v.size()){
            return 0;
        }
        if(dp[i][count]!=-1)
            return dp[i][count];
        
        int ans1 = count*v[i] + calc(v,i+1,count+1,dp);
        int ans2 = calc(v,i+1,count,dp);
        
        return dp[i][count] = max(ans1,ans2);
    }
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>> dp(v.size()+1,vector<int>(v.size()+1,-1));
        return calc(v,0,1,dp);
    }
};
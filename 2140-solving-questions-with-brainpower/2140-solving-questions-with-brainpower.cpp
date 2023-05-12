class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        
        dp[n-1]=questions[n-1][0];
        
        for(int i= n-2; i >= 0; i--){
        long long solve = questions[i][0] + ((i+questions[i][1]+1)<n?dp[i+questions[i][1]+1]:0);
            long long notsolve = dp[i+1];
            dp[i]=max(solve,notsolve);
        }
        // for(int i : dp)
        //     cout<<i<<" ";
        return dp[0];
    }
};
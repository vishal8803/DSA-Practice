class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        
        dp[n-1] = triangle[n-1];
        
        for(int i = n-2; i>=0; i--){
            dp[i] = vector<int>(triangle[i].size());
            for(int j = 0; j < triangle[i].size(); j++){
                int sum = min(triangle[i][j] + dp[i+1][j+1], triangle[i][j] + dp[i+1][j]);
                dp[i][j] = sum;
            }
            
        }
        
        // for(int i = 0; i < n; i++){
        //     for(int j : dp[i]){
        //         cout<<j<<" ";
        //     }cout<<endl;
        // }
        
        return dp[0][0];
    }
};
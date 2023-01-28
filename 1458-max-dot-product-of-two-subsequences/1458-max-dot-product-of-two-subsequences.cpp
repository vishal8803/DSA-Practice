class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1e7));
        
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                int r1 = nums1[i-1]*nums2[j-1];
                int r2 = r1 + dp[i-1][j-1];
                int r3 = dp[i-1][j];
                int r4 = dp[i][j-1];
                
                dp[i][j] = max(max(r1, r2), max(r3,r4));
            }
        }
        
        return dp[n1][n2];
    }
};
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int calc(vector<vector<int>> &matrix, int n, int m, int i, int j, int prev, vector<vector<int>> &dp, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || matrix[i][j] <= prev){
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
         
        visited[i][j] = true;  
        int t1 = calc(matrix,n,m,i+1,j,matrix[i][j],dp,visited);
        int t2 = calc(matrix,n,m,i-1,j,matrix[i][j],dp,visited);
        int t3 = calc(matrix,n,m,i,j+1,matrix[i][j],dp,visited);
        int t4 = calc(matrix,n,m,i,j-1,matrix[i][j],dp,visited);
        visited[i][j] = false;
        
        dp[i][j] = 1 + max(max(t1,t2),max(t3,t4));
        
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int mx = INT_MIN;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dp[i][j] == -1){
                    mx = max(mx, calc(matrix,n,m,i,j,-1,dp,visited));
                }
            }
        }
        
        return mx;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
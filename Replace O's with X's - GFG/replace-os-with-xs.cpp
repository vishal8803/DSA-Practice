//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>> &mat, int i, int j, vector<vector<bool>> &visited) {
        if(i < 0 or j < 0 or i >= mat.size() or j >= mat[0].size() or visited[i][j] or mat[i][j] == 'X') return;
        mat[i][j] = '#';
        visited[i][j] = true;
        dfs(mat, i+1, j, visited);
        dfs(mat, i-1, j, visited);
        dfs(mat, i, j-1, visited);
        dfs(mat, i, j+1, visited);
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 or j == 0 or i == n - 1 or j == m - 1) and mat[i][j] == 'O' and !visited[i][j]) {
                    dfs(mat, i, j, visited);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O') mat[i][j] = 'X';
                else if(mat[i][j] == '#') mat[i][j] = 'O';
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == '0' or visited[i][j]) return;
        
        visited[i][j] = true;
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i+1, j+1);
        dfs(grid, visited, i+1, j-1);
        dfs(grid, visited, i-1, j-1);
        dfs(grid, visited, i-1, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' and !visited[i][j]) {
                    count++;
                    dfs(grid, visited, i, j);
                } 
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
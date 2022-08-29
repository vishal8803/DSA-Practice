class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j]=='0') {
            return;
        }
        visited[i][j] = true;
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
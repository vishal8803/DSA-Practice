class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j]) 
            return;
        
        vis[i][j] = true;
        dfs(grid, i + 1, j, vis);
        dfs(grid, i - 1, j, vis);
        dfs(grid, i, j + 1, vis);
        dfs(grid, i, j - 1, vis);
    }
    
    int countIslands(vector<vector<int>> &grid, int n, int m) {
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 and !visited[i][j]) {
                    count++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return count;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(countIslands(grid,n,m) != 1) return 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if(countIslands(grid, n, m) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};
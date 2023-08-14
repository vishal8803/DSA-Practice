class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, queue<pair<int,int>> &q) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0 or vis[i][j] ) {
            return;
        }
        
        q.push({i, j});
        vis[i][j] = 1;
        
        dfs(grid, vis, i + 1, j, q);
        dfs(grid, vis, i, j + 1, q);
        dfs(grid, vis, i, j - 1, q);
        dfs(grid, vis, i - 1, j, q);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid.size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, vis, i, j, q);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        int level = 0;
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                auto it = q.front();
                q.pop();
                
                for(auto &direction : directions) {
                    int nx = direction[0] + it.first;
                    int ny = direction[1] + it.second;
                    
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or vis[nx][ny]) continue;
                    
                    if(grid[nx][ny] == 1) return level;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            level++;
        }
        return -1;
    }
};
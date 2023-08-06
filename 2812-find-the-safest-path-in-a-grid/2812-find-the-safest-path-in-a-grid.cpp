class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    bool bfs(vector<vector<int>> &v, int mid, int n, int m) {
        if(v[0][0] < mid) return false;
        queue<pair<int,int>> q;
        q.push({0, 0});
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = true;
        
        while(q.size() > 0) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            if(x == n - 1 and y == m - 1) return true;
            
            for(auto &direction : directions) {
                int nx = x + direction[0];
                int ny = y + direction[1];

                if(nx < 0 or ny < 0 or nx >= n or ny >= m or vis[nx][ny] or v[nx][ny] < mid) continue;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
        
        return false;
    }
    
    bool isReachable(vector<vector<int>> &v, int mid, int n, int m) {
        
        return bfs(v, mid, n, m);
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> v(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m));
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1) {
                    v[i][j] = 0;
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        
        
        int level = 1;
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                
                for(auto &direction : directions) {
                    int nx = x + direction[0];
                    int ny = y + direction[1];
                    
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or vis[nx][ny]) continue;
                    v[nx][ny] = level;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            level++;
        }
        
        
        int st = 0;
        int end = 1000;
        
        int res;
        while(st <= end) {
            int mid = (st + end)/2;
            if(isReachable(v, mid, n, m)) {
                res = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
    }
};
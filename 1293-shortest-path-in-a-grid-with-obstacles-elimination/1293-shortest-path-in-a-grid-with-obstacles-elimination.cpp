class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        queue<vector<int>> q;
        
        q.push({0,0,0,k});
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, -1));
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                auto t = q.front();
                int x = t[0];
                int y = t[1];
                q.pop();
                
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                
                if(x == n-1 and y == m-1) return t[2];
                
                if(grid[x][y]==1) {
                    if(t[3] > 0) t[3]--;
                    else continue;
                }
                
                if(visited[x][y] != -1 and visited[x][y] >= t[3]) continue;
                visited[x][y] = t[3];
                
                for(auto it : directions) {
                    int nx = x + it[0];
                    int ny = y + it[1];
                    q.push({nx, ny, t[2] + 1, t[3]});
                }
            }
        }
        
        return -1;
    }
};

/*
00
10
10
10
10
10
00
01
01
01
00
10
10
00

*/
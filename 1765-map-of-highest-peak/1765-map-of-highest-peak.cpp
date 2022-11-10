class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j]) {
                    q.push({i,j});
                    visited[i][j] = true;
                    ans[i][j] = 0;
                }
            }
        }
        
        vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0},{0,-1}};
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(auto &it : directions) {
                    int nx = x + it[0];
                    int ny = y + it[1];
                    
                    if(nx >= 0 and ny >= 0 and nx < n and ny < m and !visited[nx][ny] and !isWater[nx][ny]) {
                        ans[nx][ny] = 1 + ans[x][y];
                        q.push({nx,ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        
        return ans;
    }
};
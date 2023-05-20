class Solution {
public:
    int trapRainWater(vector<vector<int>>& v) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        int n = v.size();
        int m = v[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    pq.push({v[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int count = 0;
        
        while(pq.size() > 0) {
            int ht = pq.top().first;
            int x = pq.top().second.first;
            int y= pq.top().second.second;
            pq.pop();
            
            for(auto direction : directions) {
                int nx = x + direction[0];
                int ny = y + direction[1];
                
                if(nx >= 0 and ny >= 0 and nx < n and ny < m and !visited[nx][ny]) {
                    if(v[nx][ny] < ht) {
                        count += ht - v[nx][ny];
                        pq.push({ht, {nx,ny}});
                    } else {
                        pq.push({v[nx][ny], {nx,ny}});
                    }
                    visited[nx][ny] = true;
                }
            }
        }
        
        return count;
    }
};
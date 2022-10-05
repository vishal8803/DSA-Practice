class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if(i < 0 or j < 0 or i>= n or j >= m) return false;
        return true;
    }
    
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 
        
        pq.push({0,{0,0}});
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        
        vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        
        while(pq.size() > 0) {
            int distance = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            for(auto &it : directions) {
                int nx = x + it[0];
                int ny = y + it[1];
                
                if(isValid(nx, ny, n, m) and distance + grid[nx][ny] < dist[nx][ny]) {
                    dist[nx][ny] = distance + grid[nx][ny];
                    pq.push({dist[nx][ny], {nx,ny}});
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};
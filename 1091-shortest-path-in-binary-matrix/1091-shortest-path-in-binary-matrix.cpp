class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        int count = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        
        vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        vector<vector<bool>> visited(n,vector<bool>(n));
        visited[0][0] = true;
        while(!q.empty()){
            int size = q.size();
            bool t = false;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x==n-1 && y==n-1)
                    return 1+count;

                for(auto it : directions){
                    int nx = x + it[0];
                    int ny = y + it[1];
                    if(nx<0 || ny<0 || nx >= n || ny >= n || visited[nx][ny] || grid[nx][ny]==1)
                        continue;
                    
                    t = true;
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }    
            }
            if(t)
                count++; 
        }
        return -1;
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int n = grid.size();
        int m = grid[0].size();
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            bool t = false;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x+1<n && grid[x+1][y]==0){
                    t=true;
                    grid[x+1][y]=1;
                    q.push({x+1,y});
                }
                if(x-1>=0 && grid[x-1][y]==0){
                    t=true;
                    grid[x-1][y]=1;
                    q.push({x-1,y});
                }
                if(y+1<m && grid[x][y+1]==0){
                    t=true;
                    grid[x][y+1]=1;
                    q.push({x,y+1});
                }
                if(y-1>=0 && grid[x][y-1]==0){
                    t=true;
                    grid[x][y-1]=1;
                    q.push({x,y-1});
                }
            }
            if(t)
                dist++;
        }
        if(dist==0)
            return -1;
        return dist;
    }
};
class Solution {
public:
    void calc(vector<vector<int>> &grid, int i, int j, int &count,vector<vector<bool>> &visited, int ex, int ey){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == -1 || visited[i][j]){
            return;
        }
        
        if(i==ex && j==ey){
            bool flag = true;
            visited[i][j] = true;
            for(int ni = 0; ni < visited.size(); ni++){
                for(int nj = 0; nj < visited[0].size(); nj++){
                    
                    if(grid[ni][nj]==-1){
                        continue;
                    }
                        
                    if(!visited[ni][nj]){
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            visited[i][j] = false;
            if(flag)
                count++;
            return;
        }
        
        visited[i][j] = true;
        calc(grid,i+1,j,count,visited,ex,ey);
        calc(grid,i,j+1,count,visited,ex,ey);
        calc(grid,i,j-1,count,visited,ex,ey);
        calc(grid,i-1,j,count,visited,ex,ey);
        visited[i][j] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m));
        int sx,sy,ex,ey;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j]==2){
                    ex = i;
                    ey = j;
                }
            }
        }
        calc(grid,sx,sy,count,visited,ex,ey);
        return count;
    }
};
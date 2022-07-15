class Solution {
public:
    int calc(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || visited[i][j])
            return 0;
        
        visited[i][j] = true;
        return 1 + calc(grid,i+1,j,visited) + calc(grid,i-1,j,visited) + calc(grid,i,j+1,visited) + calc(grid,i,j-1,visited);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(51,vector<bool>(51,false));
        int mx = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    mx = max(mx, calc(grid,i,j,visited));
                }
            }
        }
        return mx;
    }
};
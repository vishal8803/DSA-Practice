class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1 || visited[i][j]){
            return;
        }
        visited[i][j]=true;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j-1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && (grid[i][j]==0)){
                    dfs(grid,visited,i,j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j]==0){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

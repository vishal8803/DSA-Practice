class Solution {
public:
     void dfs(vector<vector<int>> &grid,int row ,int col)
    {
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0 || grid[row][col]==-1)
        {
            return ;
        }
        grid[row][col] = -grid[row][col];
        dfs(grid,row-1,col);
        dfs(grid,row,col-1);
        dfs(grid,row,col+1);
        dfs(grid,row+1,col);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0 ; i<grid.size() ; i++)
        {
            dfs(grid,i,0);
        }
        for(int i=0 ; i<grid.size() ; i++)
        {
            dfs(grid,i,grid[0].size()-1);
        }
        for(int i=0 ; i<grid[0].size() ; i++)
        {
            dfs(grid,0,i);
        }
        for(int i=0 ; i<grid[0].size() ; i++)
        {
            dfs(grid,grid.size()-1,i);
        }
        int count =0 ;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                    count++ ;
            }
        }
        return count ;
    }
};
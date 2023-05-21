class Solution {
public:
 void accumulateFirstIsland(vector<vector<int>>& grid, int i ,int j,queue<pair<int,int>> &q, vector<vector<bool>> &visited)
        {
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==0)
            {
                return ;
            }
            visited[i][j] = true; 
            q.push({i,j});
            accumulateFirstIsland(grid,i-1,j,q,visited);
            accumulateFirstIsland(grid,i,j+1,q,visited);
            accumulateFirstIsland(grid,i+1,j,q,visited);
            accumulateFirstIsland(grid,i,j-1,q,visited);
        }
    
        int shortestBridge(vector<vector<int>>& grid) {
            
            
        int n = grid.size();
        int m = grid[0].size();
            vector<vector<bool>> visited(n,vector<bool>(m,false));
        //Finding the first island
        bool find = false; 
        queue<pair<int,int>> q ;
        for(int i=0 ; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    accumulateFirstIsland(grid,i,j,q,visited);
                    find = true ;
                    break;
                }
            }
            if(find)
                break;
        }
        int level =0 ;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x+1<grid.size() )
                {
                    if(  grid[x+1][y]==0)
                    {
                        visited[x+1][y] = true ;
                       grid[x+1][y] = 1 ;
                    q.push({x+1,y}); 
                    }else if(grid[x+1][y]==1 && !visited[x+1][y])
                    {
                        return level ;
                    }
                    
                }
                if(x-1>=0  )
                {
                    if(  grid[x-1][y]==0)
                    {
                        visited[x-1][y] = true ;
                       grid[x-1][y]=1 ;
                    q.push({x-1,y});
                    }else if(grid[x-1][y]==1  && !visited[x-1][y])
                    {
                        return level ;
                    }
                    
                }
                if(y-1>=0  )
                {
                     if( grid[x][y-1]==0)
                    {
                         visited[x][y-1] = true ;
                       grid[x][y-1]=1 ;
                    q.push({x,y-1});
                    }else if(grid[x][y-1]==1 && !visited[x][y-1])
                    {
                        return level ;
                    }
                }
                if(y+1<grid[0].size() )
                {
                      if(  grid[x][y+1]==0)
                    {
                          visited[x][y+1] = true ;
                       grid[x][y+1]=1 ;
                    q.push({x,y+1});
                    }else if(grid[x][y+1]==1 && !visited[x][y+1])
                    {
                        return level ;
                    }
                }
            }
            // cout<<"hello";
            level++ ;
        }
            return level ;
    }
};
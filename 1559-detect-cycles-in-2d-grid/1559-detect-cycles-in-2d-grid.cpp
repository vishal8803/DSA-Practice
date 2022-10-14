class Solution {
public:
    bool isEqual(int i, int j, int x, int y) {
        if(i==x and j==y) return true;
        
        return false;
    }
    
    bool detectCycle(vector<vector<char>> &grid, vector<vector<bool>> &visited, char ch, int i, int j, int previ, int prevj) {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || (i==previ and j==prevj) || grid[i][j] != ch) return false;
        
        if(visited[i][j]) return true;
        
        visited[i][j] = true;
        
        if(!isEqual(i+1, j, previ, prevj) and detectCycle(grid, visited, ch, i+1, j, i, j)) return true;
        if(!isEqual(i-1, j, previ, prevj) and detectCycle(grid, visited, ch, i-1, j, i, j)) return true;
        if(!isEqual(i, j+1, previ, prevj) and detectCycle(grid, visited, ch, i, j+1, i, j)) return true;
        if(!isEqual(i, j-1, previ, prevj) and detectCycle(grid, visited, ch, i, j-1, i, j)) return true;
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] and detectCycle(grid, visited, grid[i][j], i, j, -1, -1)) return true;
            }
        }
        
        return false;
    }
};
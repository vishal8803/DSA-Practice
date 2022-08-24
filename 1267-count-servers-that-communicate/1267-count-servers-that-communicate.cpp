class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> rows(n);
        vector<int> cols(m);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]==1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]==1 && (rows[i] > 1 || cols[j] > 1)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
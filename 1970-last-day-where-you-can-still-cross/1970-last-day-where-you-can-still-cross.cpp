class Solution {
public:
    void fillMatrix(vector<vector<int>> &v, vector<vector<int>> &cells, int mid) {
        for(int i = 0; i <= mid; i++) {
            int x = cells[i][0];
            int y = cells[i][1];
            v[x-1][y-1] = 1;
        }
    }
    
    bool dfs(vector<vector<int>> &v, vector<vector<int>> &vis, int i, int j) {
        if(i < 0 or j < 0 or i >= v.size() or j >= v[0].size() or v[i][j] == 1 or vis[i][j]) 
            return false;
        
        if(i == v.size() - 1) return true;
        
        vis[i][j] = 1;
        if(dfs(v, vis, i + 1, j)) return true;
        if(dfs(v, vis, i, j + 1)) return true;
        if(dfs(v, vis, i, j - 1)) return true;
        if(dfs(v, vis, i-1, j)) return true;
        
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> v(row, vector<int>(col, 0));
        int day;
        int st = 0;
        int end = cells.size() - 1;
        
        
        
        while(st <= end) {
            int mid = (st + end) / 2;
            vector<vector<int>> temp(row, vector<int>(col, 0));
            v = temp;
            fillMatrix(v, cells, mid);
            bool res = 0;
            vector<vector<int>> vis = temp;
            for(int i = 0; i < col; i++) {
                
                if(v[0][i] == 0 and dfs(v, vis, 0, i)) {
                    res = 1;
                    break;
                }
            }
            
            if(res) {
                day = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return day + 1;
    }
};
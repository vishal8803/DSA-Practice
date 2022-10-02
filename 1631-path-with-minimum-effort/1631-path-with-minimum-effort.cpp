class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
    bool calc(vector<vector<int>> &heights, vector<vector<bool>> &visited, int i, int j, int n, int m, int mxDiff) {
        if(i==n-1 and j== m-1) return true;
        visited[i][j] = true;
        
        for(auto it : directions) {
            int nx = i + it[0];
            int ny = j + it[1];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && abs(heights[i][j] - heights[nx][ny]) <= mxDiff) {
                if(calc(heights, visited, nx, ny, n, m, mxDiff)) return true;
            }
        }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int st = 0;
        int end = 1e9;
        int ans = 1e9;
        
        int n = heights.size();
        int m = heights[0].size();
        
        while(st <= end) {
            int mid = (st+end)/2;
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            if(calc(heights, visited, 0, 0, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return ans;
    }
};
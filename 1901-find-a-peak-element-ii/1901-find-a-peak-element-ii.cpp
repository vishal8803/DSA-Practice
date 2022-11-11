class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int left = INT_MIN;
                int right = INT_MIN;
                int up = INT_MIN;
                int down = INT_MIN;
                
                if(i > 0) up = mat[i-1][j];
                if(j > 0) left = mat[i][j-1];
                if(i < n - 1) down = mat[i+1][j];
                if(j < m - 1) right = mat[i][j+1];
                
                if(mat[i][j] > left and mat[i][j] > right and mat[i][j] > up and mat[i][j] > down) return {i,j};
            }
        }
        
        return {-1,-1};
    }
};
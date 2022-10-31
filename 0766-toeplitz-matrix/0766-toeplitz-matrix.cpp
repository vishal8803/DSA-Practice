class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int j = 0; j < m; j++) {
            int elem = matrix[0][j];
            for(int i = 0, k = j; i < n and k < m; i++,k++){
                if(matrix[i][k] != elem) return false;
            }
        }
        
        for(int i = 0; i < n; i++) {
            int elem = matrix[i][0];
            for(int j = 0, k = i; k < n and j < m; j++,k++){
                if(matrix[k][j] != elem) return false;
            }
        }
        
        return true;
    }
};
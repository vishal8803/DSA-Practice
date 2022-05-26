class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                if(matrix[i][j] != 0)
                matrix[i][j] = 1 + min(matrix[i+1][j+1],min(matrix[i+1][j],matrix[i][j+1]));
            }
        }
        
        int s = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                s += matrix[i][j];
            }
        }
        
        return s;
    }
};
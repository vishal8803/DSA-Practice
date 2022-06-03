class NumMatrix {
public:
    vector<vector<int>> col,temp;
    NumMatrix(vector<vector<int>>& matrix) {
        temp = matrix;
        col = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        
        for(int j = 0; j < matrix[0].size(); j++){
            int sum = 0;
            for(int i = 0; i < matrix.size(); i++){
                sum += matrix[i][j];
                col[i][j] = sum;
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int j = col1; j<=col2; j++){
            sum += col[row2][j]-col[row1][j] + temp[row1][j];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
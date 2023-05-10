class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n,vector<int>(n));
        
        int count = 1;
        int row_st = 0, row_end = n-1, col_st = 0, col_end = n-1;
        
        while(row_st <= row_end && col_st <= col_end){
            for(int j = col_st; j <= col_end; j++){
                a[row_st][j] = count;
                count++;
            }
            row_st++;
            
            for(int i = row_st; i <= row_end; i++){
                a[i][col_end] = count;
                count++;
            }
            col_end--;
            
            for(int j = col_end; j>=col_st; j--){
                a[row_end][j] = count;
                count++;
            }
            row_end--;
            
            for(int i = row_end; i>=row_st; i--){
                a[i][col_st] = count;
                count++;
            }
            col_st++;
        }
        return a;
        
    }
};
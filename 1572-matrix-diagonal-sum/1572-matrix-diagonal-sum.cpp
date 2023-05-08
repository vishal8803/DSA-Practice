class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int middle = n/2;
        int sum = 0;
        for(int i=0,j=0; i<n; i++,j++){
            sum += mat[i][j];
        }

        for(int i=0,j=n-1; i<n; i++,j--){
            sum += mat[i][j];
        }
        
        if(n%2){
            sum -= mat[middle][middle];
        }
        return sum;
    }
};
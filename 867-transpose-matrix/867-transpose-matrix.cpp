class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n==m){
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < i; j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            return matrix;
        }
        vector<vector<int>> ans(m,vector<int>(n));
        
        int j = 0;
        for(vector<int> v : matrix){
            int i = 0;
            for(i = 0; i < v.size(); i++){
                ans[i][j] = v[i];
            }
            j++;
        }
        
        return ans;
    }
};
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m,0));
        ans[0] = matrix[0];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j  < m; j++){
                ans[i][j] = matrix[i][j] ^ ans[i-1][j];
            }
        }
        
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back(ans[i][0]);
            for(int j = 1; j < m; j++) {
                temp.push_back(ans[i][j] ^ temp[temp.size()-1]);
            }
        }
        
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        return temp[k-1];
    }
};
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count = 0;
        int mn = INT_MAX;
        long long sum = 0;
        int n = matrix.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mn = min(mn, abs(matrix[i][j]));
                if(matrix[i][j] < 0) {
                    count++;
                }
                sum += abs(matrix[i][j]);
            }
        }
        
        if(count%2==0) {
            return sum;
        } else {
            return sum - 2*mn;
        }
        
        return 0;
    }
};
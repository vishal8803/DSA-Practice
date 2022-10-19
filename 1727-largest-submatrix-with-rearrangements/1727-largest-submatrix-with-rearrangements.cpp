class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> v(n, vector<int>(m,0));
        
        for(int j = 0; j < m; j++) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(matrix[i][j]==1) count++;
                else count = 0;
                
                v[i][j] = count;
            }
        }
        
        int mx = 0;
        
        for(auto it : v) {
            vector<int> t = it;
            sort(t.begin(), t.end(), greater<int>());
            
            for(int i = 0; i < t.size(); i++) {
                mx = max(mx, t[i]*(i+1));
            }
        }
        
        return mx;
    }
};
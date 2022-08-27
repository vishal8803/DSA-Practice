class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        
        for(int i = 0; i < m; i++) {
            vector<int> sums(n,0);
            for(int j = i; j < m; j++) {
                for(int k = 0; k < n; k++) {
                    sums[k] += matrix[k][j];
                }
                set<int> st = {0};
                int r = 0;
                for(int sum : sums) {
                    r += sum;
                    auto it = st.lower_bound(r - k);
                    if(it != st.end()) {
                        ans = max(ans, r - *it);
                    }
                    st.insert(r);
                }
            }
        }
        
        return ans;
    }
};
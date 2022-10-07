class Solution {
public:
    int canWeConvert(int i, int num, int x) {
        int diff = abs(i-num);
        
        if(diff%x==0) return diff/x;
        
        return -1;
    }
    
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> v;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v.push_back(grid[i][j]);
            }
        }
        
        sort(v.begin(), v.end());
        
        int size = v.size();
        int num = v[size/2];
        int res = 0;
        
        for(int i : v) {
            int count = canWeConvert(i,num,x);
            if(count == -1) {
                return -1;
            }
            res += count;
        }
        
        return res;
    }
};
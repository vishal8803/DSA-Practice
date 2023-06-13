class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int count = 0;
        
        int n = a.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                bool flag = true;
                for(int k = 0; k < n; k++) {
                    if(a[i][k] != a[k][j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        
        vector<vector<char>> ans(m, vector<char>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = box[n - j - 1][i];
            }
        }
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(ans[i][j] == '.') {
                    bool flag = false;
                    int idx = i - 1;

                    while(idx >= 0) {
                        if(ans[idx][j] == '*') break;
                        if(ans[idx][j] == '#') {
                            flag = true;
                            break;
                        }
                        idx--;
                    }

                    if(flag) {
                        ans[i][j] = '#';
                        ans[idx][j] = '.';
                    }
                }
            }
        }
        
        return ans;
    }
};
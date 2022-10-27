class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int res = 0;
        for(int i = -n + 1; i < n; i++) {
            for(int j = -n + 1; j < n; j++) {
                int cnt = 0;
                for(int ni = 0; ni < n; ni++) {
                    for(int nj = 0; nj < n; nj++) {
                        if(ni + i < 0 || ni + i >= n || nj + j < 0 || nj + j >= n) 
                            continue;
                        if(img1[ni][nj] + img2[ni + i][nj + j] == 2) cnt++;
                    }
                }
                res = max(res, cnt);
            }
        }
        
        return res;
    }
};
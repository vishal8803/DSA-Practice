class Solution {
public:
    void calc(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j, int prev){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || ocean[i][j]==1 || prev>heights[i][j])
            return;
        
        ocean[i][j] = 1;
        calc(heights, ocean, i+1, j, heights[i][j]);
        calc(heights, ocean, i-1, j, heights[i][j]);
        calc(heights, ocean, i, j+1, heights[i][j]);
        calc(heights, ocean, i, j-1, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++){
            if(pacific[i][0] == 0){
                calc(heights, pacific, i, 0, INT_MIN);
            }
        }
        
        for(int j = 0; j < m; j++){
            if(pacific[0][j] == 0){
                calc(heights, pacific, 0, j, INT_MIN);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(atlantic[i][m-1] == 0){
                calc(heights, atlantic, i, m-1, INT_MIN);
            }
        }
        
        for(int j = 0; j < m; j++){
            if(atlantic[n-1][j] == 0){
                calc(heights, atlantic, n-1, j, INT_MIN);
            }
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <m; j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
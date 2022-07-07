class Solution {
public:
    void calc(vector<vector<int>>& land, int i, int j, vector<vector<bool>>& visited, vector<vector<int>> &ans, int n, int m, int ni, int nj){
        if(i<0 || j<0 || i>=n || j>=m || land[i][j]==0 || visited[i][j]){
            return;
        }
        visited[i][j] = true;
        if(i==n-1 && j==m-1){
            ans.push_back({ni,nj,i,j});
            // return;
        }else if(i+1<n && j+1<m && land[i+1][j]==0 && land[i][j+1]==0){
            ans.push_back({ni,nj,i,j});
            // return;
        }else if(i+1==n && land[i][j+1]==0){
            ans.push_back({ni,nj,i,j});
            // return;
        }else if(j+1==m && land[i+1][j]==0){
            ans.push_back({ni,nj,i,j});
            // return;
        }
        calc(land,i+1,j,visited,ans,n,m,ni,nj);
        calc(land,i,j+1,visited,ans,n,m,ni,nj);
        calc(land,i,j-1,visited,ans,n,m,ni,nj);
        calc(land,i-1,j,visited,ans,n,m,ni,nj);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j]==1 && !visited[i][j]){
                    calc(land,i,j,visited,ans,n,m, i, j);
                }
            }
        }
        
        return ans;
    }
};
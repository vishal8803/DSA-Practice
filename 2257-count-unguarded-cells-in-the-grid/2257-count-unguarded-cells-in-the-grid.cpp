class Solution {
public:
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m,vector<int>(n,1));
        
        for(auto it : walls){
            mat[it[0]][it[1]] = 0;
        }
        
        for(vector<int> guard : guards) {
            int x = guard[0];
            int y = guard[1];
            mat[x][y] = 2;
        }
        
        for(vector<int> guard : guards) {
            int x = guard[0];
            int y = guard[1];
            
            for(int i = x-1; i>=0; i--){
                if(mat[i][y]==0 || mat[i][y]==2)
                    break;
                mat[i][y] = -1;
            }
            
            for(int i = x+1; i<m; i++){
                if(mat[i][y]==0 || mat[i][y]==2)
                    break;
                mat[i][y] = -1;
            }
            
            for(int j = y-1; j>=0; j--){
                if(mat[x][j]==0 || mat[x][j]==2)
                    break;
                mat[x][j] = -1;
            }
            
            for(int j = y+1; j<n; j++){
                if(mat[x][j]==0 || mat[x][j]==2)
                    break;
                mat[x][j] = -1;
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
        }
        
        return count;
    }
};
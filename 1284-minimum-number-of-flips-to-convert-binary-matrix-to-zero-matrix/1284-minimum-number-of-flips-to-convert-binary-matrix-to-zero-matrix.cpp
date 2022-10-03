class Solution {
public:
    
    void flipAllAdjacent(vector<vector<int>> &mat, int i, int j, int &c) {
        if(mat[i][j]) c--;
        else c++;
        
        mat[i][j] = 1 - mat[i][j];
        
        if(i-1>=0) {
            if(mat[i-1][j]) c--;
            else c++;
            mat[i-1][j] = 1 - mat[i-1][j];
        }
        
        if(i+1 < mat.size()) {
            if(mat[i+1][j]) c--;
            else c++;
            
            mat[i+1][j] = 1 - mat[i+1][j];
        }
        
        if(j-1>=0) {
            if(mat[i][j-1]) c--;
            else c++;
            mat[i][j-1] = 1 - mat[i][j-1];
        }
        
        if(j+1 < mat[0].size()) {
            if(mat[i][j+1]) c--;
            else c++;
            mat[i][j+1] = 1 - mat[i][j+1];
        }
    }
    
    
    
    int calc(vector<vector<int>> &mat, vector<vector<bool>> &visited, int &oneCount) {
        if(oneCount == 0) {
            return 0;
        }
        
        int count = INT_MAX;
        
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(!visited[i][j]){
                    flipAllAdjacent(mat,i,j,oneCount);
                    visited[i][j] = true;
                    int t = calc(mat,visited, oneCount);
                    if(t != -1) count = min(count, 1 + t);
                    visited[i][j] = false;
                    flipAllAdjacent(mat,i,j,oneCount);
                }
            }
        }
        
        return count==INT_MAX?-1:count;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        set<pair<int,int>> st;
        int count = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j]) count++;
            }
        }
        
        return calc(mat,visited,count);
    }
};
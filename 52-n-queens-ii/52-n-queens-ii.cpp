class Solution {
public:
    bool canPlace(int row, int col, vector<vector<int>> &temp){
        for(int i = row-1, j =col; i>=0; i--){
            if(temp[i][j]==1)
                return false;
        }
        
        for(int i = row-1, j = col-1; i>=0 && j>=0; i-- && j--){
            if(temp[i][j]==1)
                return false;
        }
        
        for(int i = row-1, j = col+1; i>=0 && j<temp.size(); i-- && j++){
            if(temp[i][j]==1)
                return false;
        }
        
        return true;
    }
    void calc(int n, int i, int &ans, vector<vector<int>> &temp){
        if(i==n){
            ans++;
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(canPlace(i,col,temp)){
                temp[i][col] = 1;
                calc(n,i+1,ans,temp);
                temp[i][col] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int count = 0;
        vector<vector<int>> temp(n,vector<int>(n,0));
        calc(n,0,count,temp);
        return count;
    }
};
class Solution {
public:
    bool canPlace(int row, int col, vector<string> &temp){
        for(int i = row-1, j =col; i>=0; i--){
            if(temp[i][j]=='Q')
                return false;
        }
        
        for(int i = row-1, j = col-1; i>=0 && j>=0; i-- && j--){
            if(temp[i][j]=='Q')
                return false;
        }
        
        for(int i = row-1, j = col+1; i>=0 && j<temp.size(); i-- && j++){
            if(temp[i][j]=='Q')
                return false;
        }
        
        return true;
    }
    void calc(int n, int i, vector<vector<string>> &ans, vector<string> &temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(canPlace(i,col,temp)){
                temp[i][col] = 'Q';
                calc(n,i+1,ans,temp);
                
                temp[i][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string elem(n,'.');
        vector<string> temp;
        
        for(int i = 0; i < n; i++){
            temp.push_back(elem);
        }
        calc(n,0,ans,temp);
        return ans;
    }
};
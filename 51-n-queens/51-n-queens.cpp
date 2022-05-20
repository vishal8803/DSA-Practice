class Solution {
public:
    bool isItSafePlaceForQueen(vector<vector<int>> &chess,  int row, int col){
        for(int i = row-1 , j=col; i>=0; i--){
            if(chess[i][j]==1)
                return false;
        }
        
        for(int i = row-1 , j = col-1; i>=0 && j>=0; i-- , j--){
            if(chess[i][j]==1)
                return false;
        }
        
        for(int i = row-1 , j = col+1; i>=0 && j<chess.size(); i-- , j++){
            if(chess[i][j]==1)
                return false;
        }
        
        return true;
    }
    void calc(vector<vector<int>> &chess, int n, int row, vector<vector<string>> &ans, vector<string> temp){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(isItSafePlaceForQueen(chess,row,col)){
                
                chess[row][col] = 1;
                string s;
                s.append(n,'.');
                s[col]='Q';
                temp.push_back(s);
                calc(chess,n,row+1,ans,temp);
                
                chess[row][col] = 0;
                s[col]='.';
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<vector<int>> chess(n,vector<int>(n,0));
        calc(chess,n,0,ans,{});
        return ans;
        
    }
};
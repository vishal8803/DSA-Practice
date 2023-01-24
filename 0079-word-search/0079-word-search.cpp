class Solution {
public:
    bool isFind = false;
void dfs(int row,int col,int index,vector<vector<char>> &board,string &word,vector<vector<int>> &vis){
        int n=board.size();
        int m=board[0].size();
        
        if(index>=word.size()|| isFind) {
            isFind = true;
            return;
        }

        vis[row][col]=1;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m
            && vis[newrow][newcol] == 0 && board[newrow][newcol]==word[index]){
                dfs(newrow,newcol,index+1,board,word,vis);
            }
        }
        vis[row][col]=0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j]==word[0] and !vis[i][j]){
                    dfs(i,j,1,board,word,vis);
                    if (isFind==true)
                        return true;
                }
            }
        }
        return false;
    }
};
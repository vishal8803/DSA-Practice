class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='.' || visited[i][j]){
            return;
        }
        
        visited[i][j] = true;
        
        if(i+1<n && board[i+1][j]=='X'){
            dfs(board,visited,i+1,j,n,m);
        }else if(j+1<m && board[i][j+1]=='X'){
            dfs(board,visited,i,j+1,n,m);
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m));
        
        int count1 = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j]=='X' && !visited[i][j]){
                    dfs(board,visited,i,j,n,m);
                    count1++;
                }
            }
        }
        return count1;
    }
};
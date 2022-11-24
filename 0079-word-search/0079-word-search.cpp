class Solution {
public:
    void test(vector<vector<char>>& board , vector<vector<bool>> &visited , string &word ,int i,bool &ans,int row ,int col)
    {
        if(i==word.length())
        {
            ans = true ;
            return ;
        }
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || visited[row][col] || board[row][col] != word[i])
            return ;
        
        visited[row][col]=true ;
        test(board,visited,word,i+1,ans,row-1,col);
        test(board,visited,word,i+1,ans,row,col-1);
        test(board,visited,word,i+1,ans,row+1, col);
        test(board,visited,word,i+1,ans,row,col+1);
        visited[row][col]=false ;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false ;
        vector<vector<bool>> visited(board.size() ,vector<bool>(board[0].size(),false));
        for(int i=0 ; i<board.size() ; i++)
        {
            for(int j=0 ; j<board[0].size() ; j++)
            {
                test(board,visited,word,0,ans,i,j);
                if(ans)
                    break ;
            }
            if(ans)
                break;
        }
        return ans ;
    }
};
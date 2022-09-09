class Solution {
public:
    bool calc(string s, string word) {
        if(s.size() != word.size()) return false;
        int i = 0;
        while(i < s.size()) {
            if(s[i] != ' ' && s[i] != word[i]) break;
            i++;
        }
        if(i == s.size()) return true;
        reverse(word.begin(), word.end());
        i = 0;
        while(i < s.size()) {
            if(s[i] != ' ' && s[i] != word[i]) break;
            i++;
        }
        if(i == s.size()) return true;
        
        return false;
    }
    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        vector<vector<int>> startPosition;
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string cs = "";
                while(j < m && board[i][j]=='#')j++;
                while(j < m && board[i][j] != '#') cs += board[i][j++];
                if(calc(cs, word)) return true;
            }
        }
        
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                string cs = "";
                while(i < n && board[i][j]=='#')i++;
                while(i < n && board[i][j] != '#') cs += board[i++][j];
                if(calc(cs,word)) return true;
            }
        }
        
        return false;
    }
};
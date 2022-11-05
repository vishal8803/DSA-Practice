class Solution {
public:
    struct Node {
        Node* links[26];
        string word = "";
    };
    
    Node* buildTrie(vector<string>& words) {
        Node* root = new Node();
        for(string word : words) {
            Node* temp = root;
            for(char ch : word) {
                if(temp->links[ch-'a'] == NULL) temp->links[ch-'a'] = new Node();
                temp = temp->links[ch-'a'];
            }
            temp->word = word;
        }
        return root;
    }
    
    void dfs(vector<vector<char>> &board, Node* root, int i, int j, vector<string> &ans) {
        char ch = board[i][j];
        if(ch == ';' or root->links[ch-'a'] == NULL) return;
        
        root = root->links[ch-'a'];
        
        if(root->word != "") {
            ans.push_back(root->word);
            root->word = "";
        }
        
        board[i][j] = ';';
        if(i > 0) dfs(board, root, i - 1, j, ans);
        if(j > 0) dfs(board, root, i, j - 1, ans);
        if(i < board.size() - 1) dfs(board, root, i + 1, j, ans);
        if(j < board[0].size() - 1) dfs(board, root, i, j + 1, ans);
        board[i][j] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        
        Node* root = buildTrie(words);
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, root, i, j, ans);
            }
        }
        
        return ans;
    }
};
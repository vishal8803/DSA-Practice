//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void calc(vector<vector<char>>& board, string& word, int i, int j, int k, bool &ans, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j]==true || board[i][j]!=word[k])
            return;
            
        if(k==word.length()-1)
        {
            ans=true;
            return;
        }
        visited[i][j]=true;
        calc(board,word,i+1,j,k+1,ans, visited);
        calc(board,word,i,j+1,k+1,ans, visited);
        calc(board,word,i-1,j,k+1,ans, visited);
        calc(board,word,i,j-1,k+1,ans, visited);
        visited[i][j]=false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        bool ans = false;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size()));
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(word[0]==board[i][j]){
                    calc(board,word,i,j,0,ans,visited);
                    if(ans)
                        return ans;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
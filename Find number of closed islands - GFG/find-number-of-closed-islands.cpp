//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j) {
        if(i < 0 or j < 0 or i >= m.size() or j >= m[0].size() or m[i][j] == 0 or visited[i][j]) return;
        
        visited[i][j] = true;
        dfs(m, visited, i+1, j);
        dfs(m, visited, i-1, j);
        dfs(m, visited, i, j+1);
        dfs(m, visited, i, j-1);
    }
    
    int closedIslands(vector<vector<int>>& m, int N, int M) {
        
        vector<vector<int>> visited(N, vector<int>(M, 0));
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(i == 0 or i == N - 1 or j == 0 or j == M - 1) {
                    if(m[i][j] and !visited[i][j]) dfs(m, visited, i, j);
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(m[i][j] and !visited[i][j]) {
                    dfs(m, visited, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
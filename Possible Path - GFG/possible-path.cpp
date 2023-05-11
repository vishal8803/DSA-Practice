//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int isPossible(vector<vector<int>>graph){
	    int N = graph.size();
	    vector<int> adj[N];
	    for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(graph[i][j]==1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int degree = 0;
        for(int i = 0; i < N; i++) {
            if(adj[i].size() & 1) return 0;
        }
        return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
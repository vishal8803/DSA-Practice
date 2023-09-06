//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int> adj[], vector<bool> &vis, int node, stack<int> &st) {
        vis[node] = true;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(adj, vis, it, st);
            }
        }
        st.push(node);
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    stack<int> st;
	    vector<bool> visited(V, false);
	    
	    for(int i = 0; i < V; i++) {
	        if(!visited[i]) {
	            dfs(adj, visited, i, st);
	        }
	    }
	    
	    int node = st.top();
	    visited.assign(V, false);
	    dfs(adj, visited, node, st);
	    for(int i = 0; i < V; i++) {
	        if(!visited[i]) return -1;
	    }
	    return node;
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
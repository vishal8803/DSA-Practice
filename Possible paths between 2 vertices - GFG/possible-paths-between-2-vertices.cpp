//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void dfs(vector<int> adj[], vector<bool> &vis, int node, int dest, int &ans) {
        if(node == dest) {
            ans++;
            return;
        }
        // vis[node] = true;
        
        for(auto it : adj[node]) {
            if(!vis[it])
                dfs(adj, vis, it, dest, ans);
        }
    }
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        int ans = 0;
        vector<bool> vis(V, false);
        dfs(adj, vis, source, destination, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends
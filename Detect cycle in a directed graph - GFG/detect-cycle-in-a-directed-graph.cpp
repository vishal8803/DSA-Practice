// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCycle(vector<int> adj[], vector<bool> &visited, vector<bool> &dfsVisited, int node){
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                bool t = isCycle(adj,visited,dfsVisited,it);
                if(t)
                    return true;
            }else if(dfsVisited[it]){
                return true;
            }
        }
        
        dfsVisited[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> dfsVisited(V);
        vector<bool> visited(V);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(isCycle(adj,visited,dfsVisited,i))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
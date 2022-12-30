//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool calc(vector<int> adj[], int node, vector<bool> &dfsVis, vector<bool> &vis) {
        vis[node] = true;
        dfsVis[node] = true;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(calc(adj, it, dfsVis, vis)) return true;
            } else if(dfsVis[it]) return true;
        }
        dfsVis[node] = false;
        return false;
    } 
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> dfsVis(V, false), vis(V, false);
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                calc(adj, i, dfsVis, vis);
            }
        }
        
        for(int i = 0; i < V; i++) {
            // cout<<dfsVis[i]<<" ";
            if(!dfsVis[i]) ans.push_back(i);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
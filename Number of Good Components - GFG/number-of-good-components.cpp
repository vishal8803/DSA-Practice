//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &adj, int node, vector<int> &temp, vector<bool> &visited) {
        visited[node] = true;
        temp.push_back(node);
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(adj, it, temp, visited);
            }
        }
    }
    
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V+1, false);
        int count = 0;
        
        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                vector<int> temp;
                dfs(adj, i, temp, visited);
                int size = temp.size();
                bool flag = true;
                for(int i : temp) {
                    if(adj[i].size() != size-1){
                        flag = false;
                        break;
                    }
                }
                if(flag) count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
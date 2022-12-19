class Solution {
public:
    bool dfs(vector<int> adj[], int source, int dest, vector<bool> &vis) {
        if(source == dest) return true;
        vis[source] = true;
        
        for(auto it : adj[source]) {
            if(!vis[it] and dfs(adj, it, dest, vis)) return true;
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto edge :edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        
        return dfs(adj, source, destination, vis);
    }
};
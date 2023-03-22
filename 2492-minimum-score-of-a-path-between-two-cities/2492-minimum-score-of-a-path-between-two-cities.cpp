class Solution {
public:
    void dfs(vector<pair<int,int>> adj[], int node, int &mn, vector<bool> &visited) {
        visited[node] = true;
        
        for(auto it : adj[node]) {
            if(!visited[it.first]) {
                
                dfs(adj, it.first, mn, visited);
            }
            mn = min(mn, it.second);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        int mn = INT_MAX;
        vector<bool> visited(n+1);
        dfs(adj, 1, mn, visited);
        return mn;
    }
};
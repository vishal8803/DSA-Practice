class Solution {
public:
    int ans = 0;
    void dfs(vector<pair<int,int>> adj[], int node, int maxTime, vector<int> &values, int curr, int currTime) {
        if(currTime > maxTime) return;
        
        int temp = values[node];
        curr += temp;
        values[node] = 0;
        
        if(node == 0) {
            ans = max(ans, curr);
        }
        
        for(auto it : adj[node]) {
            dfs(adj, it.first, maxTime, values, curr, currTime + it.second);
        }
        
        values[node] = temp;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int,int>> adj[n];
        
        for(auto &edge : edges) {
            int x = edge[0];
            int y = edge[1];
            int wt = edge[2];
            
            adj[x].push_back({y, wt});
            adj[y].push_back({x, wt});
        }
        dfs(adj, 0, maxTime, values, 0, 0);
        return ans;
        
    }
};
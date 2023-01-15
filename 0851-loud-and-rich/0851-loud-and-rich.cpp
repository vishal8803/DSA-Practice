class Solution {
public:
    
    void calc(vector<int> adj[], vector<int>& quiet, int node, int &ans, int &val, vector<bool> &visited) {
        visited[node] = true;
        if(ans > quiet[node]) {
            val = node;
            ans = quiet[node];
        }
        
        for(auto it : adj[node]) {
            if(!visited[it])
                calc(adj, quiet, it, ans, val, visited);
        }
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        
        vector<int> adj[n];
        
        for(auto it : richer) {
            int a = it[0];
            int b = it[1];
            
            adj[b].push_back(a);
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int res = INT_MAX, val;
            vector<bool> visited(n,false);
            calc(adj, quiet, i, res, val, visited);
            ans.push_back(val);
        }
        
        return ans;
    }
};
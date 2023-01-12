class Solution {
public:
    vector<int> calc(vector<int> adj[], int node, vector<int> &ans, string &labels, vector<bool> &vis) {
        vis[node] = true;
        char ch = labels[node];
        
        vector<int> f(26, 0);
        f[ch - 'a']++;
        
        for(auto &it : adj[node]) {
            if(!vis[it]) {
                vector<int> temp = calc(adj, it, ans, labels, vis);
                for(int i = 0; i < 26; i++) {
                    f[i] += temp[i];
                }
            }
        }
        
        ans[node] = f[ch - 'a'];
        return f;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<int> ans(n, 0);
        vector<bool> vis(n, false);
        calc(adj, 0, ans, labels, vis);
        
        return ans;
    }
};
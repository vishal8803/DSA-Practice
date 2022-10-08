class Solution {
public:
    void dfs(vector<int> adj[], vector<bool> &visited, vector<int> &ans, int node) {
        visited[node-1] = true;
        vector<bool> avl(5,0);
        
        for(auto it : adj[node]) {
            // if(visited[it] and ans[it-1] != 0) {
            //     avl[ans[it-1]] = 1;
            // } 
            if(!visited[it-1]){
                dfs(adj, visited, ans, it);
            }
        }
        
        for(auto it : adj[node]) {
            avl[ans[it-1]] = 1;
        }
        
        for(int i = 1; i <= 4; i++) {
            if(!avl[i]){
                ans[node-1] = i;
                break;
            }
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n,0);
        
        vector<int> adj[n+1];
        
        for(auto path : paths) {
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }
        
        vector<bool> visited(n,false);
        // ans[0] = 1;
        // visited[0] = true;
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i-1]) {
                dfs(adj, visited, ans, i);
            }
        }
        
        return ans;
    }
};
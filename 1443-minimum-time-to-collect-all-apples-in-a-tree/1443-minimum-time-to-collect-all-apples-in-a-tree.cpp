class Solution {
public:
    bool dfs(vector<int> adj[], vector<bool> &hasApple, vector<bool> &visited, int node, int &count) {
        visited[node] = true;
        bool flag = false;
        
        if(hasApple[node]) {
            flag = true;
        } 
        
        for(auto it : adj[node]) {
            if(!visited[it] && dfs(adj, hasApple, visited, it, count)) {
                flag = true;
                count += 2;
            }
        }
        
        return flag;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        } 
        
        vector<bool> visited(n,false);
        int count = 0;
        dfs(adj, hasApple, visited, 0, count);
        return count;
    }
};
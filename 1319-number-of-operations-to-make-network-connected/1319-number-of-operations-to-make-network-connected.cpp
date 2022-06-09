class Solution {
public:
    void dfs(vector<int> adj[], vector<bool> &visited, int node){
        visited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(adj,visited,it);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalWires = connections.size();
        
        if(totalWires + 1 < n)
            return -1;
        
        vector<int> adj[n];
        
        for(auto connection : connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        int count = 0;
        vector<bool> visited(n);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
        }
        
        return count-1;
    }
};
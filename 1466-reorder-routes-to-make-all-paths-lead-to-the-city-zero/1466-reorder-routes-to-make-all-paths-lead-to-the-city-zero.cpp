class Solution {
public:
    void dfs(vector<int> adj[], int node, vector<bool> &visited, int &count, set<pair<int,int>> &st) {
        visited[node] = true;
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                if(st.find({node, it}) != st.end()) count++;
                dfs(adj, it, visited, count, st);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        set<pair<int,int>> st;
        
        for(auto connection : connections) {
            int x = connection[0];
            int y = connection[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
            st.insert({x,y});
        }
        
        int count = 0;
        vector<bool> visited(n, false);
        dfs(adj, 0, visited, count, st);
         
        return count;
    }
};
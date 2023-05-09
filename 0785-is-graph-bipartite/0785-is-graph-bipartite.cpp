class Solution {
public:
    bool calc(vector<vector<int>> &graph, int node, vector<int> &color) {
        if(color[node] == -1) color[node] = 1;
        
        for(auto it : graph[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(calc(graph, it, color) == false) return false;
            } else if(color[it] == color[node]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(calc(graph, i, color) == false) return false;
            }
        }
        
        return true;
    }
};
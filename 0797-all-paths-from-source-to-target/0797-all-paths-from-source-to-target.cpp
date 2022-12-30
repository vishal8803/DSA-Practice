class Solution {
public:
    void dfs(vector<vector<int>> &graph, int n, int node, set<vector<int>> &st, vector<int> &temp) {
        temp.push_back(node);
        
        if(node == n-1) {
            
            if(st.find(temp) == st.end()) {
                st.insert(temp);
            }
            temp.pop_back();
            return;
        }
        
        for(auto it : graph[node]) {
            dfs(graph, n, it, st, temp);
        }
        
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        
        set<vector<int>> st;
        vector<int> temp;
        dfs(graph, n, 0, st, temp);
        
        for(auto it : st) {
            ans.push_back(it);
        }
        
        return ans;
    }
};
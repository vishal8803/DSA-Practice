class Solution {
public:
    bool calc(vector<vector<int>> &adj, bool vis[], bool dfsvis[], vector<int> &st, int node){
        vis[node] = true;
        dfsvis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(calc(adj,vis,dfsvis,st,it)){
                    return st[node] = true;
                }
            }else if(dfsvis[it]){
                return st[node] = true;
            }
        }
        dfsvis[node] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        bool vis[n],dfsvis[n];
        memset(vis,false,sizeof(vis));
        memset(dfsvis,false,sizeof(dfsvis));
        vector<int> st(n,false);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                calc(graph,vis,dfsvis,st,i);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!st[i]){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
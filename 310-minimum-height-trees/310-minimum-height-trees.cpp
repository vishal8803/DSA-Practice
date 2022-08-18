class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        
        vector<unordered_set<int>> adj(n);
        
        for(auto edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(adj[i].size()==1) {
                q.push(i);
            }
        }
        
        while(n>2) {
            int len = q.size();
            n -= len;
            
            for(int i = 0; i < len; i++) {
                int node = q.front();
                q.pop();
                
                for(auto it : adj[node]) {
                    adj[it].erase(node);
                    if(adj[it].size()==1) {
                        q.push(it);
                    }
                }
            }
        }
        
        vector<int> ans;
        while(q.size() > 0) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
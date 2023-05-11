class Solution {
public:
    bool calc(vector<int> adj[], int node, vector<bool> &vis, vector<bool> &dfsVis) {
        vis[node] = true;
        dfsVis[node] = true;
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(calc(adj, it, vis, dfsVis)) return true;
            } else if(dfsVis[it]) return true;
        }
        dfsVis[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false), dfsVis(V, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(calc(adj, i, visited, dfsVis)) return true;
            }
        }
        return false;
    }
    void dfs(vector<int> adj[], int node, stack<int> &st, vector<bool> &visited) {
        visited[node] = true;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(adj, it, st, visited);
            }
        }
        st.push(node);
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> items[n];
        
        
        int count = m;
        for(int i = 0; i < group.size(); i++) {
            if(group[i] == -1) {
                group[i] = count++;
            }
        }
        
        vector<int> g[m + count];
        
        for(int i = 0; i < n; i++) {
            for(int beforeItem : beforeItems[i]) {
                if(beforeItem != i)
                    items[beforeItem].push_back(i);
                if(group[beforeItem] != group[i]){
                    g[group[beforeItem]].push_back(group[i]);
                }
            }
        }
        
        if(isCyclic(n, items) or isCyclic(m+count, g)) return {};
        
        vector<bool> visited(n, 0);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(items, i, st, visited);
            }
        }
        
        vector<bool> visited2(m+count,0);
        stack<int> st2;
        
        for(int i = 0; i < m + count; i++) {
            if(!visited2[i]) {
                dfs(g, i, st2, visited2);
            }
        }
        
        
        map<int, vector<int>> mp;
        
        while(st.size() > 0) {
            int num = st.top();
            st.pop();
            
            mp[group[num]].push_back(num);
        }
        vector<int> ans;
        while(st2.size() > 0) {
            int num = st2.top();
            st2.pop();
            
            for(int i : mp[num]) ans.push_back(i);
        }
        
        return ans;
    }
};
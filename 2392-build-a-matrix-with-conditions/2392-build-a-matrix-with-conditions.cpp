class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>> v) {
        vector<int> topo;
        vector<int> indegree(n+1,0);
        vector<int> adj[n+1];
        
        for(auto it : v) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(q.size() > 0) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return topo;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans;
        
        vector<int> row = topoSort(k, rowConditions);
        vector<int> col = topoSort(k, colConditions);
        
        if(row.size() != k or col.size() != k) return ans;
        
        ans = vector<vector<int>>(k, vector<int>(k,0));
        
        unordered_map<int,int> mp;
        for(int i = 0; i < col.size(); i++) {
            mp[col[i]] = i;
        }
        
        for(int i = 0; i < row.size(); i++) {
            ans[i][mp[row[i]]] = row[i];
        }
        
        return ans;
    }
};
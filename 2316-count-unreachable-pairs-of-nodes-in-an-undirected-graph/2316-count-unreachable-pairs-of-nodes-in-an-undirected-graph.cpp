class Solution {
public:
    void dfs(vector<int> adj[], int node, vector<bool> &visited, int &count){
        visited[node] = true;
        count++;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(adj,it,visited,count);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        long long ans = 0;
        
        vector<bool> visited(n,false);
        vector<int> temp;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int count = 0;
                dfs(adj,i,visited,count);
                temp.push_back(count);
            }
        }
        
        vector<long long> sum(temp.size());
        long long s = 0;
        for(int i = sum.size()-1; i>=0; i--){
            s += temp[i];
            sum [i] = s;
        }
        
        for(int i = 0; i < temp.size()-1; i++){
            ans += (long long)((long long)temp[i]*(long long)sum[i+1]);
        }
        
        return ans;
    }
};
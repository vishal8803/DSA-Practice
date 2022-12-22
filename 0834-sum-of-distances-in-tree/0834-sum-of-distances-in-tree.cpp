class Solution {
public:
    void postOrder(vector<int> adj[], int node, int prev, vector<int> &cnt, vector<int> &res) {
        for(auto i : adj[node]) {
            if(i == prev) continue;
            postOrder(adj, i, node, cnt, res);
            cnt[node] += cnt[i];
            res[node] += res[i] + cnt[i];
        }
        cnt[node]++;
    }
    
    void preOrder(vector<int> adj[], int node, int prev, vector<int> &cnt, vector<int> &res) {
        for(auto i : adj[node]) {
            if(i == prev) continue;
            res[i] = res[node] - cnt[i] + cnt.size() - cnt[i];
            preOrder(adj, i, node, cnt, res);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> cnt(n), res(n);
        
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        postOrder(adj, 0, -1, cnt, res);
        preOrder(adj, 0, -1, cnt, res);
        return res;
    }
};
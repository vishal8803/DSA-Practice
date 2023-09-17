class Solution {
public:
    int calc(vector<int> adj1[], vector<int> adj2[], int node, vector<int> &vis, vector<int> &score) {
        vis[node] = 1;
        int total = 0;
        
        for(auto &it : adj1[node]) {
            if(vis[it]) continue;
            total += calc(adj1, adj2, it, vis, score);
        }
        
        for(auto &it : adj2[node]) {
            if(vis[it]) continue;
            total += 1 + calc(adj1, adj2, it, vis, score);
        }
        
        return score[node] = total;
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        
        vector<int> adj1[n], adj2[n];
        
        for(auto &edge : edges) {
            adj1[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        
        vector<int> score(n, 0);
        vector<int> vis(n, 0);
        int val = calc(adj1, adj2, 0, vis, score);
        ans[0] = val;
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        vector<int> vis2(n, 0);
        vis2[0] = 1;
        
        
        
        while(q.size() > 0) {
            int node = q.front().first;
            int curr = q.front().second;
            q.pop();
            
            ans[node] = curr + score[node];
            
            for(auto &it : adj1[node]) {
                if(vis2[it]) continue;
                
                vis2[it] = 1;
                q.push({it, ans[node] - score[it] + 1});
            }
            
            for(auto &it : adj2[node]) {
                if(vis2[it]) continue;
                
                vis2[it] = 1;
                q.push({it, ans[node] - score[it] - 1});
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int n) {
        vector<vector<int>> adj[n];
        
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            int wt = edge[2];
            adj[x].push_back({y, wt});
            adj[y].push_back({x, wt});
        } 
        
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        map<vector<int>, int> used;
        
        int cnt = 0;
        
        while(pq.size()) {
            int moves = pq.top().first;
            int node = pq.top().second;
            pq.pop(); 
            
            if(moves > dist[node]) continue;
            
            cnt++;
            
            for(auto it : adj[node]) {
                int nnode = it[0];
                int wt = it[1];
                used[{node, nnode}] = min(wt, M - moves);
                
                int d2 = moves + wt + 1;
                if(d2 < min(dist[nnode], M + 1)) {
                    pq.push({d2, nnode});
                    dist[nnode] = d2;
                }
            }
        }
        
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            int wt = edge[2];
            
            cnt += min(wt, used[{x,y}] + used[{y, x}]);
        }
        
        return cnt;
    }
};
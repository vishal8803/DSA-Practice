class Solution {
public:
    
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        
        for(int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            double z = succProb[i];
            
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
        vector<double> dist(n, 0.0);
        priority_queue<pair<double,int>, vector<pair<double,int>>> pq;
        dist[start] = 1.0;
        pq.push({1.0, start});
        
        while(pq.size() > 0) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(node == end) continue;
            
            for(auto it : adj[node]) {
                double np = prob*it.second;
                if(dist[it.first] < np) {
                    dist[it.first] = np;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        
        return dist[end];
    }
};
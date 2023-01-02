class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        
        for(auto &road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        
        int mod = 1e9 + 7;
        
        while(pq.size() > 0) {
            int size = pq.size();
            while(size--) {
                auto it = pq.top();
                pq.pop();
                
                long long d = it.first;
                int node = it.second;
                
                for(auto it : adj[node]) {
                    if(dist[it.first] > it.second + d) {
                        dist[it.first] = d + it.second;
                        ways[it.first] = ways[node]%mod;
                        pq.push({dist[it.first], it.first});
                    } else if(dist[it.first] == it.second + d) {
                        ways[it.first] = (ways[it.first]%mod + ways[node]%mod)%mod;
                    }
                }
            }
        }
        
        return ways[n-1];
    }
};
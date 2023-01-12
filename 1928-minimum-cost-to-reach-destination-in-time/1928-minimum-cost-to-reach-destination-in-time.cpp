class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int ans = INT_MAX;
        int n = passingFees.size();
        vector<pair<int,int>> adj[n];
        
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            int time = edge[2];
            
            adj[x].push_back({y,time});
            adj[y].push_back({x,time});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({passingFees[0], 0, 0});
        
        vector<int> time(n, INT_MAX);
        time[0] = 0;
        
        while(pq.size() > 0) {
            auto it = pq.top();
            pq.pop();
            
            int node = it[2];
            int cost = it[0];
            int t = it[1];
            
            if(node == n - 1) {
                return cost;
            }
            
            for(auto val : adj[node]) {
                if(t + val.second > maxTime or t + val.second >= time[val.first]) {
                    continue;
                }
                time[val.first] = t + val.second;
                pq.push({cost + passingFees[val.first], time[val.first], val.first});
            }
        }
        
        return -1;
    }
};
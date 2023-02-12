class Solution {
public:
    long long cost = 0;
    
    int calc(vector<int> adj[], int node, vector<bool> &visited, int seats) {
        visited[node] = true;
        int temp = 1;
        
        for(int it : adj[node]) {
            if(!visited[it]) {
                temp += calc(adj, it, visited, seats);
            }
        }
        
        cost += (temp + seats - 1) / seats;
        return temp;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> adj[n + 1];
        
        for(auto road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        vector<bool> visited(n + 1, false);
        visited[0] = true;
        for(auto i : adj[0]) {
            if(!visited[i]) {
                calc(adj, i, visited, seats);
            }
        }
        
        return cost;
    }
};
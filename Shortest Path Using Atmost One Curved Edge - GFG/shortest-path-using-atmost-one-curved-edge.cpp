//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<long long> calc(vector<pair<int,int>> adj[], int src, int n) {
        vector<long long> dist(n+1, INT_MAX);
        queue<pair<long long,int>> pq;
        pq.push({0, src});
        dist[src] = 0;
        
        while(pq.size() > 0) {
            auto p = pq.front();
            pq.pop();
            
            int node = p.second;
            long long d = p.first;
            
            for(int i = 0; i < adj[node].size(); i++) {
                if(dist[adj[node][i].first] > d + (long long)adj[node][i].second) {
                    dist[adj[node][i].first] = d + adj[node][i].second;
                    pq.push({dist[adj[node][i].first], adj[node][i].first});
                }
            }
        }
        
        return dist;
    }
    
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<pair<int,int>> adj1[n+1];
        
        
        for(int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            int w1 = edges[i][2];
            int w2 = edges[i][3];
            
            adj1[x].push_back({y, w1});
            adj1[y].push_back({x, w1});
        }
        
        vector<long long> v1 = calc(adj1, a, n);
        vector<long long> v2 = calc(adj1, b, n);
        
        long long cost = min(v1[b], v2[a]);
        
        for(int i = 0; i < edges.size(); i++) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int wt2 = edges[i][3];
            
            long long t = v1[node1] + v2[node2] + wt2;
            long long t2 = v1[node2] + v2[node1] + wt2;
            cost = min(cost, t2);
            cost = min(cost, t);
        }
        if(cost >= INT_MAX) return -1;
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends
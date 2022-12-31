//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n];
        
        for(auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        q.push({0, {src, 0}});
        
        while(q.size() > 0) {
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int d = it.second.second;
            
            if(node == dst || stops == k+1) continue;
            
            for(auto it2 : adj[node]) {
                if(dist[it2.first] > d + it2.second) {
                    dist[it2.first] = d + it2.second;
                    q.push({stops + 1, {it2.first, dist[it2.first]}});
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1;
        
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
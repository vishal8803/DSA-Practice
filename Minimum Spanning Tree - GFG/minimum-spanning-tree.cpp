// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> mstSet(V,false);
        vector<int> dist(V,INT_MAX);
        vector<int> parent(V,-1);
        
        
        dist[0] = 0;
        
        
        for(int i = 1; i < V; i++){
            
            int mn = INT_MAX;
            int u;
            
            for(int v = 0; v < V; v++){
                if(mstSet[v]==false && mn > dist[v]){
                    mn = dist[v];
                    u = v;
                }
            }
            
            mstSet[u] = true;
            
            for(auto it : adj[u]){
                if(mstSet[it[0]]==false && dist[it[0]] > it[1]){
                    dist[it[0]] = it[1];
                    parent[it[0]] = u;
                }
            }
        }
        
        int sum = 0;
        for(int i = 0; i < V; i++){
            sum += dist[i];
        }
        
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
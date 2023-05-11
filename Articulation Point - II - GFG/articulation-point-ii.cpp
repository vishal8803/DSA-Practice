//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int timer = 0;
    
    void dfs(vector<int> graph[], vector<bool> &vis, int low[], int tin[], int node, int parent, vector<int> &mark) {
        vis[node] = true;
        low[node] = tin[node] = timer;
        timer++;
        int child = 0;
        for(auto it : graph[node]) {
            if(it == parent) continue;
            if(!vis[it]) {
                dfs(graph, vis, low, tin, it, node, mark);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] and parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
        
        if(child > 1 and parent == -1) mark[node] = 1;
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int tin[V], low[V];
        vector<bool> vis(V, 0);
        vector<int> mark(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(adj, vis, low, tin, i, -1, mark);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i]) ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
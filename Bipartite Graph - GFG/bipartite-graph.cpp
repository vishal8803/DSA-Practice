// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool calc(vector<int> adj[], int node, vector<int> &color){
        if(color[node]==-1){
            color[node] = 1;
        }
        
        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it] = 1 - color[node];
                if(calc(adj,it,color)==false)
                    return false;
            }else if(color[it]==color[node])
                return false;
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    for(int i = 0; i < V; i++){
        if(color[i] == -1){
            if(calc(adj,i,color)==false){
                return false;
            }
        }
    }
    
    return true;
	}

};

// { Driver Code Starts.
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
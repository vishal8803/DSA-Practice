// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void countPaths(vector<int> adj[], int dst, int node, vector<bool> &visited,int &count){
        if(node==dst){
            count++;
            return;
        }
        if(visited[node]){
            return;
        }
        
        visited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                countPaths(adj,dst,it,visited,count);
            }
        }
        visited[node] = false;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<int> adj[n];
	    
	    for(vector<int> edge : edges){
	        int x = edge[0];
	        int y = edge[1];
	        adj[x].push_back(y);
	    }
	    
	    vector<bool> visited(n,false);
	    int count = 0;
	    countPaths(adj,d,s,visited,count);
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool canColor(vector<int> adj[], vector<int> &color, int m, int n, int node){
    
    if(node==n)
        return true;
    
    
    for(int i = 0; i < m; i++){
        bool flag = true;
        for(auto it : adj[node]){
            if(color[it]==i){
                flag = false;
                break;
            }
        }
        
        if(flag){
            color[node] = i;
            if(canColor(adj,color,m,n,node+1))
                return true;
            color[node] = -1;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n,-1);
    
    vector<int> adj[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j)
                continue;
            if(graph[i][j])
                adj[i].push_back(j);
        }
    }
    return canColor(adj,color,m,n,0);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
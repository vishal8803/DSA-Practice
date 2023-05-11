//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
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
    
    
    int doctorStrange(int N, int M, vector<vector<int>> & graph)
    {
        vector<int> adj[N+1];
        for(auto it : graph) {
            if(it.size() == 2) {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        }
        
         vector<bool> vis(N + 1, 0);
         int low[N+1], tin[N+1];
         vector<int> ans(N+1, 0);
         int cnt = 0;
         for(int i = 1; i <= N; i++) {
             if(!vis[i])
                dfs(adj, vis, low, tin, i, -1, ans);
         }
         for(int i = 1; i <= N; i++) {
             if(ans[i] == 1) cnt++;
         }
         return cnt;
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout<<ans<<endl;
    }
	return 0;
}
// } Driver Code Ends
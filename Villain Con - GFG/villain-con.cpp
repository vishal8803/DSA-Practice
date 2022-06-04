// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dfs(vector<int> adj[], int node, vector<bool> &visited, vector<int> &dp){
        if(dp[node] != -1)
            return dp[node];
            
        int mx = 0;
        
        visited[node] = true;
        
        for(int i : adj[node]){
            mx = max(mx,dfs(adj,i,visited,dp));
        }
        
        return dp[node] = 1 + mx;
    }
    
    int minColour(int N, int M, vector<int> mat[]) {
        vector<bool> visited(N+1,false);
        
        vector<int> dp(N+1, -1);
        
        vector<int> adj[N+1];
        
        for(int i = 0; i < M; i++){
            adj[mat[i][1]].push_back(mat[i][0]);
        }
        
        int mx = 0;
        
        for(int i = 1; i <= N; i++){
            if(visited[i]) continue;
            
            int pathLength = dfs(adj,i,visited,dp);
            
            mx = max(mx,pathLength);
        }
        
        // for(int i : dp)
        //     cout<<i<<" ";
        
         return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    // -1 i need a camera
    // 0 means i have a camera
    // 1 means i am covered
    
    int calc(vector<int> adj[], int node, int &ans, vector<bool> &visited, int parent) {
        
        if(adj[node].size() == 1 and adj[node][0] == parent) {visited[node] = true; return -1;}
        
        bool flag = false;
        visited[node] = true;
        bool cflag = false;
        bool one = false;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                int res = calc(adj, it, ans, visited, node);
                if(res == -1) {
                    cflag = true;
                } else if(res == 0) {
                    flag = true;
                } else{
                    one = true;
                }
            }
        }
        if(cflag || one) {
            ans++;
            return 0;
        }
        else if(flag) return 1;
        if(!flag) {ans++; return 0;}
        return -1;
    }
    
    int countVertex(int N, vector<vector<int>>edges){
        vector<int> adj[N+1];
        vector<bool> visited(N+1, false);
        
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        
        int ans = 0;
        
        int temp = calc(adj, 1, ans, visited,-1);
        if(temp == -1) ans++;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
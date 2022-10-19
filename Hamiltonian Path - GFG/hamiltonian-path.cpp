//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool isHamiltonian(vector<int> adj[], int node, vector<bool> &visited, vector<int> &temp, int n) {
        
        if(temp.size() == n) return true;
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                temp.push_back(it);
                visited[it] = true;
                if(isHamiltonian(adj, it, visited, temp, n)) return true;
                temp.pop_back();
                visited[it] = false;
            }
        }
        
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> adj[N+1];
        
        for(auto edge : Edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(N+1, false);
        vector<int> temp;
        
        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                temp.push_back(i);
                visited[i] = true;
                if(isHamiltonian(adj, i, visited, temp, N)) return true;
                temp.pop_back();
                visited[i] = false;
            }
        }
        
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends
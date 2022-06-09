// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int> adj[], int node, vector<bool> &visited, stack<int> &st){
	    visited[node] = true;
	    
	    for(auto it : adj[node]){
	        if(!visited[it]){
	            dfs(adj,it,visited,st);
	        }
	    }
	    
	    st.push(node);
	}
	
	void dfs2(vector<int> adj[], int node, vector<bool> &visited){
	    visited[node] = true;
	    
	    for(auto it : adj[node]){
	        if(!visited[it]){
	            dfs2(adj,it,visited);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        int count = 0;
        vector<bool> visited(V);
        stack<int> st;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(adj,i,visited,st);
            }
        }
        
        vector<int> adj2[V];
        
        for(int i = 0; i < V; i++){
            for(int elem : adj[i]){
                adj2[elem].push_back(i);
            }
            visited[i] = false;
        }
        
        while(!st.empty()){
            int i = st.top();
            st.pop();
            if(!visited[i]){
                count++;
                dfs2(adj2,i,visited);
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
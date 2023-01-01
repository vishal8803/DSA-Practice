//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int parent[501];
	int rnk[501];
	
	void makeset(int n) {
	    for(int i = 0; i < n; i++) {
	        parent[i] = i;
	        rnk[i] = 0;
	    }
	}
	
	int findParent(int node) {
	    if(node == parent[node]) return node;
	    
	    return parent[node] = findParent(parent[node]);
	}
	
	void makeUnion(int node1, int node2) {
	    node1 = findParent(node1);
	    node2 = findParent(node2);
	    
	    if(rnk[node1] > rnk[node2]) {
	        parent[node2] = node1;
	    } else if(rnk[node2] > rnk[node1]) {
	        parent[node1] = node2;
	    } else {
	        parent[node1] = node2;
	        rnk[node1]++;
	    }
	}
	
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        makeset(V);
        vector<vector<int>> edges;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j])
                    edges.push_back({i,j});
            }
        }
        set<int> st;
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            if(findParent(x) == findParent(y)) continue;
            makeUnion(x,y);
        }
        
        for(int i = 0; i < V; i++) {
            st.insert(findParent(i));
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
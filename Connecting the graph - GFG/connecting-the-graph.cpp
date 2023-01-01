//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int parent[100001];
	int rnk[100001];
	
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
	
    
    int Solve(int n, vector<vector<int>>& edge) {
        if(edge.size() + 1 < n) return -1;
        set<int> st;
        makeset(n);
        for(auto edg : edge) {
            int x = edg[0];
            int y = edg[1];
            if(findParent(x) == findParent(y)) continue;
            makeUnion(x,y);
        }
        for(int i = 0; i < n; i++) {
            st.insert(findParent(i));
        }
        
        return st.size() - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        set<pair<int,int>> st;
        vector<int> dist(n+1, INT_MAX);
        vector<pair<int,int>> adj[n+1];
        dist[1] = 0;
        
        for(auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        dist[1] = 0;
        st.insert({0,1});
        
        while(st.size() > 0) {
            auto t = st.begin();
            st.erase(t);
            int d = (*t).first;
            int node = (*t).second;
            
            for(auto it : adj[node]) {
                if(dist[it.first] > d + it.second) {
                    dist[it.first] = d + it.second;
                    st.insert({dist[it.first], it.first});
                }
            }
        }
        
        // for(int i : dist) cout<<i<<" ";
        if(dist[n] == INT_MAX) return {-1};
        queue<pair<int,int>> q;
        q.push({n, dist[n]});
        vector<int> ans;
        // ans.push_back(n);
        
        while(q.size() > 0) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int d = it.second;
            
            ans.push_back(node);
            for(auto it : adj[node]) {
                if(d-it.second == dist[it.first]) {
                    q.push({it.first, dist[it.first]});
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
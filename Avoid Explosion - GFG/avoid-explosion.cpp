//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int parent[1001];
    
    
    void makeset(int n) {
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }
    
    void makeUnion(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        
        parent[u] = v;
    }
    
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m) {
        vector<string> ans;
        makeset(n);
        for(auto &m : mix) {
            int x = m[0];
            int y = m[1];
            int p1 = findParent(x);
            int p2 = findParent(y);
            
            bool d = false;
            
            for(auto &t : danger) {
                int ds1 = findParent(t[0]);
                int ds2 = findParent(t[1]);
                
                if((p1 == ds1 and p2 == ds2) or (p1 == ds2 and p2 == ds1)) {
                    d = true;
                    break;
                }
            }
            
            if(!d) {
                ans.push_back("Yes");
                makeUnion(x,y);
            } else {
                ans.push_back("No");
                parent[x] = p1;
                parent[y] = p2;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
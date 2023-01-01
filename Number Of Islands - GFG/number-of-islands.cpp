//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet {
    public:
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int findParent(int node) {
        if(parent[node] == node) return parent[node];
        
        return parent[node] = findParent(parent[node]);
    }
    
    void makeUnion(int node1, int node2) {
        node1 = findParent(node1);
        node2 = findParent(node2);
        
        if(rank[node1] > rank[node2]) {
            parent[node2] = node1;
            rank[node1] += rank[node2];
        } else {
            parent[node1] = node2;
            rank[node2] += rank[node1];
        }
    }
};

class Solution {
  public:
    bool isValid(int nx, int ny, int n, int m) {
        if(nx >= 0 and ny >= 0 and nx < n and ny < m) return true;
        return false;
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        
        int count = 0;
        vector<int> ans;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        for(auto it : operators) {
            int x = it[0];
            int y = it[1];
            
            if(visited[x][y]) {
                ans.push_back(count);
                continue;
            }
            visited[x][y] = true;
            count++;
            for(int i = 0; i < 4; i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                
                if(isValid(nx, ny, n, m)) {
                    if(visited[nx][ny]) {
                        int node1 = x*m + y;
                        int node2 = nx*m + ny;
                        // cout<<node1<<" "<<node2<<endl;
                        if(ds.findParent(node1) != ds.findParent(node2)) {
                            // cout<<x<<" "<<y<<endl;
                            ds.makeUnion(node1, node2);
                            count--;
                        }
                    }
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};

// 0 1 0 1
// 1 1 1 1


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
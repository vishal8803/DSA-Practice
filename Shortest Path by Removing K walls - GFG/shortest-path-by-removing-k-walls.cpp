//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        queue<vector<int>> q;
        q.push({0,0,0,k});
        vector<vector<int>> visited(n, vector<int>(m, -1));
        
        while(q.size() > 0) {
            auto it = q.front();
            q.pop();
            int x = it[0];
            int y = it[1];
            
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            
            if(x == n - 1 and  y == m - 1) return it[2];
            
            if(mat[x][y] == 1) {
                if(it[3] > 0) it[3]--;
                else continue;
            }
            
            if(visited[x][y] != -1 and visited[x][y] >= it[3]) continue;
            
            visited[x][y] = it[3];
            q.push({x + 1, y, it[2] + 1, it[3]});
            q.push({x - 1, y, it[2] + 1, it[3]});
            q.push({x, y + 1, it[2] + 1, it[3]});
            q.push({x, y - 1, it[2] + 1, it[3]});
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
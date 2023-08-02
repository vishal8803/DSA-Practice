//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        map<vector<int>, vector<vector<int>>> mp;
        map<vector<int>, int> dist;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        for(int i = 0; i < N; i++) 
        {
            for(int j = 0; j < M; j++) 
            {
                dist[{i,j}] = INT_MAX;
                if(A[i][j] == 1){
                    for(int k = 0; k < 4; k++) {
                        int nx = i + directions[k][0];
                        int ny = j + directions[k][1];
                        
                        if(nx < 0 or ny < 0 or nx >= N or ny >= M or A[nx][ny] == 0) 
                            continue;
                            
                        mp[{i,j}].push_back({nx, ny, 1});
                        mp[{nx,ny}].push_back({i, j, 1});
                    }
                }
            }
        }
        
        dist[{0,0}] = 0;
        queue<vector<int>> q;
        q.push({0, 0, 0});
        
        while(q.size() > 0) {
            auto it = q.front();
            q.pop();
            int d = it[0];
            int x = it[1];
            int y = it[2];
            
            if(x == X and y == Y) return d;
            
            for(auto it2 : mp[{x,y}]) {
                int nd = it2[2];
                int nx = it2[0];
                int ny = it2[1];
                if(dist[{nx,ny}] > d + nd) {
                    dist[{nx, ny}] = d + nd;
                    q.push({d + nd, nx, ny});
                }
            }
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
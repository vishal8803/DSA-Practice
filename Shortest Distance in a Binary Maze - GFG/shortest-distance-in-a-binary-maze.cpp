//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        visited[source.first][source.second] = true;
        queue<pair<int,int>> q;
        q.push(source);
        int count = 0;
        
        while(q.size() > 0) {
            int size = q.size();
            bool flag =  false;
            while(size--) {
                auto it = q.front();
                q.pop();
                
                if(it == destination) return count;
                
                for(auto dir : directions) {
                    int nx = dir[0] + it.first;
                    int ny = dir[1] + it.second;
                    
                    if( nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny]==1 and !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        flag = true;
                        q.push({nx,ny});
                    }
                }
            }
            if(flag) count++;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
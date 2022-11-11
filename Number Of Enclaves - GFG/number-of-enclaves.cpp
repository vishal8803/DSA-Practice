//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void f(vector<vector<int>> grid , vector<vector<int>> & visited , int a , int b){
        queue<pair<int,int>> q;
        q.push({a,b});
        int sx = grid.size();
        int sy = grid[0].size();
        visited[a][b] = 1;
        while(q.size()){
            pair<int,int> p = q.front();
            q.pop();
            int px = p.first;
            int py = p.second;
            if(px-1>=0 && (grid[px-1][py]==1 && !visited[px-1][py])){
                q.push({px-1,py});
                visited[px-1][py] = 1;
            }
            if(px+1<sx && (grid[px+1][py]==1 && !visited[px+1][py])){
                q.push({px+1,py});
                visited[px+1][py] = 1;
            }
            if(py-1>=0 && (grid[px][py-1]==1 && !visited[px][py-1])){
                q.push({px,py-1});
                visited[px][py-1] = 1;
            }
            if(py+1<sy && (grid[px][py+1]==1 && !visited[px][py+1])){
                q.push({px,py+1});
                visited[px][py+1] = 1;
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int y = grid[0].size();
        int x = grid.size();
        vector<vector<int>> visited;
        for(int i = 0 ; i < x ; i++){
            vector<int>temp(y,0);
            visited.push_back(temp);
        }
        for(int i = 0 ; i < y ; i++){
            if(grid[0][i] && !visited[0][i]){
                f(grid,visited,0,i);
            }
        }
        for(int i = 0 ; i < y ; i++){
            if(grid[x-1][i] && !visited[x-1][i]){
                f(grid,visited,x-1,i);
            }
        }
        for(int i = 0 ; i < x ; i++){
            if(grid[i][0] && !visited[i][0]){
                f(grid,visited,i,0);
            }
        }
        for(int i = 0 ; i < x ; i++){
            if(grid[i][y-1] && !visited[i][y-1]){
                f(grid,visited,i,y-1);
            }
        }
        int ans = 0 ;
        for(int i = 1 ; i < x-1 ; i++){
            for(int j = 1 ; j < y-1 ; j++){
                if(grid[i][j] && !visited[i][j]){
                    ans++;
                }
            }
        }
        return ans;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
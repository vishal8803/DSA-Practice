//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        
        int count = 0;
        
        vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0, -1}};
        
        while(q.size() > 0) {
            int size = q.size();
            bool flag = false;
            while(size--) {
                auto it = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nx = it.first + directions[i][0];
                    int ny = it.second + directions[i][1];
                    
                    if(nx >= 0 and ny >= 0 and nx < n and ny < m and !visited[nx][ny] and grid[nx][ny]==1) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        grid[nx][ny] = 2;
                        flag = true;
                    }
                }
            }
            if(flag) count++;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
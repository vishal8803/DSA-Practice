//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<int,int>> q;
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<bool>> visited(n,vector<bool>(m));
	    vector<vector<int>> ans(n,vector<int>(m));
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                visited[i][j] = true;
	                ans[i][j] = 0;
	            }
	        }
	    }
	    
	    int count = 1;
	    while(!q.empty()){
	        int size = q.size();
	        bool flag = false;
	        while(size--){
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            
	            if(x+1<n && grid[x+1][y]==0 && !visited[x+1][y]){
	                ans[x+1][y] = count;
	                visited[x+1][y] = true;
	                q.push({x+1,y});
	                flag = true;
	            }
	            
	            if(x-1>=0 && grid[x-1][y]==0 && !visited[x-1][y]){
	                ans[x-1][y] = count;
	                visited[x-1][y] = true;
	                q.push({x-1,y});
	                flag = true;
	            }
	            
	            if(y+1<m && grid[x][y+1]==0 && !visited[x][y+1]){
	                ans[x][y+1] = count;
	                visited[x][y+1] = true;
	                q.push({x,y+1});
	                flag = true;
	            }
	            
	            if(y-1>=0 && grid[x][y-1]==0 && !visited[x][y-1]){
	                ans[x][y-1] = count;
	                visited[x][y-1] = true;
	                q.push({x,y-1});
	                flag = true;
	            }
	        }
	        if(flag)
	            count++;
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>> &image, vector<vector<bool>> &visited, int i, int j, int nc, int oc) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || visited[i][j] || image[i][j] != oc) return;
        
        visited[i][j] = true;
        image[i][j] = nc;
        dfs(image, visited, i+1, j, nc, oc);
        dfs(image, visited, i-1, j, nc, oc);
        dfs(image, visited, i, j-1, nc, oc);
        dfs(image, visited, i, j+1, nc, oc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(image, visited, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
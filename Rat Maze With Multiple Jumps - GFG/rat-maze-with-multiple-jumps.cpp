// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool calc(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &path, int n){
        
        if(i==n-1 && j==n-1){
            path[i][j] = 1;
            return true;
        }
            
        if(i>=n || j>=n || i<0 || j<0 || mat[i][j]==0)
            return false;
            
        path[i][j] = 1;
        
        
            
        for(int k = 1; k<=mat[i][j]; k++){
            if(calc(i,j+k,mat,path,n)) return true;
            if(calc(i+k,j,mat,path,n)) return true;
        }
        
        path[i][j] = 0;
        
        return false;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	   vector<vector<int>> ans(n,vector<int>(n,0));
	   
	   if(calc(0,0,matrix,ans,n)){
	       return ans;
	   }
	   return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
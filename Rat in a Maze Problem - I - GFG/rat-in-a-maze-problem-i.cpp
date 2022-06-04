// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int i, int j, vector<vector<int>> &m, int n, string temp, vector<string> &ans, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0 || visited[i][j])
            return;
            
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        visited[i][j] = true;
        
        dfs(i+1,j,m,n,temp+"D",ans,visited);
        dfs(i,j+1,m,n,temp+"R",ans,visited);
        dfs(i,j-1,m,n,temp+"L",ans,visited);
        dfs(i-1,j,m,n,temp+"U",ans,visited);
        
        visited[i][j] = false;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n,vector<bool>(n));
        
        dfs(0,0,m,n,"",ans,visited);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
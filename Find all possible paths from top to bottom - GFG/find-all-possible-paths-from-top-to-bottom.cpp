// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void calc(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &ans, vector<int> temp){
        if(i>=n || j>=m)
            return;
            
        if(i==n-1 && j==m-1){
            temp.push_back(grid[i][j]);
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(grid[i][j]);
        calc(grid,i+1,j,n,m,ans,temp);
        calc(grid,i,j+1,n,m,ans,temp);
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        calc(grid,0,0,n,m,ans,{});
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends
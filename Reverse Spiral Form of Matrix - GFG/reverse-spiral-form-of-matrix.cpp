//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isValid(int r1, int r2, int c1, int c2) {
        if(r1 > r2 or c1 > c2) return false;
        
        return true;
    }
    
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int> ans;
        int row_st = 0;
        int row_end = a.size() - 1;
        int col_st = 0;
        int col_end = a[0].size() - 1;
        
        while(row_st <= row_end and col_st <= col_end) {
            for(int j = col_st; j <= col_end; j++) {
                ans.push_back(a[row_st][j]);
            }
            row_st++;
            
            if(!isValid(row_st, row_end, col_st, col_end)) break;
            
            for(int i = row_st; i <= row_end; i++) {
                ans.push_back(a[i][col_end]);
            }
            col_end--;
            
            if(!isValid(row_st, row_end, col_st, col_end)) break;
            
            for(int j = col_end; j >= col_st; j--) {
                ans.push_back(a[row_end][j]);
            }
            row_end--;
            
            if(!isValid(row_st, row_end, col_st, col_end)) break;
            
            for(int i = row_end; i >= row_st; i--) {
                ans.push_back(a[i][col_st]);
            }
            col_st++;
            
            if(!isValid(row_st, row_end, col_st, col_end)) break;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
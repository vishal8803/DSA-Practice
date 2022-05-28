// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        
        int rows = 4*n;
        int cols = 4*n;
        
        vector<vector<int>> temp(rows,vector<int>(cols));
        int num = 1;
        
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                temp[i-1][j-1] = num++;
            }
        }
        
        vector<int> coil1,coil2;
        vector<vector<int>> ans;
        
        int row_st = rows-1;
        int col_st = cols-1;
        int row_end = 0;
        int col_end = 0;
        
        while(row_st >= row_end && col_st >= col_end){
            for(int i = row_st; i >= row_end; i--){
                coil1.push_back(temp[i][col_st]);
            }
            
            row_st--;
            col_st--;
            
            for(int j = col_st; j >= col_end+1; j--){
                coil1.push_back(temp[row_end][j]);
            }
            row_end++;
            col_end++;
            
            for(int i = row_end; i<=row_st; i++){
                coil1.push_back(temp[i][col_end]);
            }
            col_end++;
            col_st--;
            
            for(int j = col_end; j<=col_st; j++){
                coil1.push_back(temp[row_st][j]);
            }
            row_st--;
            row_end++;
        }
        
        row_st = 0;
        col_st = 0;
        row_end = rows-1;
        col_end = cols-1;
        
        while(row_st<=row_end && col_st<=col_end){
            for(int i = row_st; i<= row_end; i++){
                coil2.push_back(temp[i][col_st]);
            }
            row_st++;
            col_st++;
            
            for(int j = col_st; j <= col_end-1; j++){
                coil2.push_back(temp[row_end][j]);
            }
            row_end--;
            col_end--;
            
            for(int i = row_end; i>=row_st; i--){
                coil2.push_back(temp[i][col_end]);
            }
            col_end--;
            col_st++;
            
            for(int j = col_end; j>=col_st; j--){
                coil2.push_back(temp[row_st][j]);
            }
            row_st++;
            row_end--;
        }
        
        reverse(coil1.begin(), coil1.end());
        reverse(coil2.begin(), coil2.end());
        
        ans.push_back(coil1);
        ans.push_back(coil2);
        
        return ans;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int currCol=0 , currRow=0 , minRow=0 , maxRow=0 , minCol=0 , maxCol =0;
        
        for(int i=0 ; i<s.size(); i++) 
        {
            char ch = s[i];
            
            if(ch == 'L') {
                currCol--;
            }
            else if(ch == 'R') {
                currCol++;
            }
            else if(ch == 'D') {
                currRow--;    
            }
            else if(ch == 'U') {
                currRow++;
            }
            else{
                continue;
            }
        
            minRow =min(minRow , currRow);
            maxRow =max(maxRow , currRow);
            minCol =min(minCol , currCol);
            maxCol =max(maxCol , currCol);
        }
        
        return ((maxRow-minRow)<n) && ((maxCol-minCol)<m) ? 1:0;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
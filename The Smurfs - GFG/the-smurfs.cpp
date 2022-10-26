//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        int cr = 0, cb = 0, cg = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] == 'R') cr++;
            else if(a[i] == 'B') cb++;
            else cg++;
        }
        
        if(cr%2 and cb%2 and cg%2) return 2;
        else if(cr%2 == 0 and cb%2 == 0 and cg%2==0) return 2;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
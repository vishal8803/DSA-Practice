//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        long long c1 = r[0];
        long long c2 = g[0];
        long long c3 = b[0];
        
        for(int i = 1; i < N; i++) {
            long long nc1 = (long long)r[i] + min(c2,c3);
            long long nc2 = (long long)g[i] + min(c1,c3);
            long long nc3 = (long long)b[i] + min(c1,c2);
            
            c1 = nc1;
            c2 = nc2;
            c3 = nc3;
        }
        
        return min(c1, min(c2,c3));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
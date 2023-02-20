//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        long long prevo = 1, preva = 0, prevb = 0, prevc = 0;
        int mod = 1e9 + 7;
        
        for(int i = 1; i <= N; i++) {
            long long curra = (prevo + prevb + prevc)%mod;
            long long currb = (prevo + preva + prevc)%mod;
            long long currc = (prevo + prevb + preva)%mod;
            long long curro = (preva + prevb + prevc)%mod;
            
            prevo = curro;
            preva = curra;
            prevb = currb;
            prevc = currc;
        }
        
        return prevo%mod;
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
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
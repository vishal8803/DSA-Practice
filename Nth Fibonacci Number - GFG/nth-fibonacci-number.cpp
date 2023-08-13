//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Initial Template for C++

int t[100002] ;
class Solution{
  public:
  long long int nfibo(long long int n)
  {
      if(n==0 || n==1)
      return n ;
      
      if(t[n] != -1)
      return t[n] ;
      
      int x,y ;
      if(t[n-1] != -1)
      {
          x = t[n-1] ;
      }else
      {
          x = nfibo(n-1) ;
      }
      
      if(t[n-2] != -1)
      {
          y = t[n-2] ;
      }else
      {
          y =  nfibo(n-2) ;
      }
      return t[n]=( x+ y )%1000000007;
  }
    long long int nthFibonacci(long long int n){
        memset(t,-1,sizeof(t)) ;
     return nfibo(n) ;   
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
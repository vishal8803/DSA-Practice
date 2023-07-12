//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends

using ll = long long;

class Solution{
    
    public:
    //You need to complete this fucntion
    int MOD = 1e9 + 7;
    
    ll powr(ll x, ll y)
    {
        ll res = 1;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res%MOD * x%MOD)%MOD;
            y = y >> 1;
            x = (x%MOD * x%MOD)%MOD;
        }
        return res % MOD;
    }
    
    long long power(int N,int R)
    {
       return powr(N,R);
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends
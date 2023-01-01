//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long power(long long x, long long y, int m)
    {
       if (y == 0)
          return 1;
       
       long long p = power(x, y / 2, m) % m;
       
       p = (p%m * p%m) % m;
     
        return (y % 2 == 0) ? p : (x * p) % m;
    }
    
    
    long long modInverse(long long a, int m)
    {
       return power(a, m - 2, m);
    }
    
	int compute_value(int n)
	{
	   int ans = 1;
	   int MOD = 1e9 + 7;
	   long long prev = 1;
	   
	   for(int i = 1; i <= n; i++) {
	       long long t = ((n-i+1)%MOD*modInverse(i, MOD)%MOD)%MOD;
	       
	       prev = (prev%MOD*t%MOD)%MOD;
	       
	       int temp = (prev%MOD * prev%MOD)%MOD;
	       ans = (ans%MOD + temp)%MOD;
	   }
	   
	   return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
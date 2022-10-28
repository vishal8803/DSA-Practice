//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    long mod = 1e9+7;
        	int ans = 2;    
        	 for(int i=1;i<n;i++){
        		  ans = ((ans % mod) * (i+1))%mod;
        		  ans = (ans % mod + 1) % mod;
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
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
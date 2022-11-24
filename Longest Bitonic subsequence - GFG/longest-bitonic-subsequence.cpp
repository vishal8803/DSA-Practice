//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>a)
	{
	    int n = a.size() ;
	    int dp[n] ;
	    dp[0] = 1 ;
	    for(int i =1 ; i<n ; i++)
	    {
	        int mx = 0 ;
	        for(int j=i-1 ; j>=0 ; j--)
	        {
	            if(a[i]>a[j])
	            {
	                mx = max(mx , dp[j]) ;
	            }
	        }
	        dp[i] = mx+1 ;
	    }
	    vector<int> bc(n,1) ;
	   // bc[0]=1 ;
	    for(int i=n-1 ; i>=0 ; i--)
	    {
	        int mx =INT_MIN ;
	        for(int j=n-1 ; j>i ; j--)
	        {
	            if(a[i]>a[j])
	            bc[i] = max(bc[i] , 1+bc[j]) ;
	        }
	       // bc[i] = mx + 1 ;
	    }
	    int nmx =INT_MIN ;
	    for(int i =0 ; i<n ;i++)
	    {
	        nmx = max(nmx , dp[i]+bc[i]-1) ;
	    }
	    return nmx ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
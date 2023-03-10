//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr, arr + n);
    	long long fmx = arr[n-1];
    	long long smx = arr[n-2];
    	long long tmx = arr[n-3];
    	long long mn = arr[0];
    	long long smn = arr[1];
    	
    	long long p1 = fmx*smx*tmx;
    	long long p2 = fmx*smn*mn;
    	
    	return max(p1, p2);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
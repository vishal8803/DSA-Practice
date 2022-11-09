//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    if(n == 1) return arr[0];
	   //  s1 + s2 = sum
	   //  s1 - s1 = min
	   //  2s1 = sum + min
	   //  2s1 - sum = min;
	   
	   
	   int sum = 0;
	   
	   for(int i = 0; i < n; i++) {
	       sum += arr[i];
	   }
	   
	   vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
	   
	   for(int i = 0; i < n; i++) {
	       dp[i][0] = true;
	   }
	   
	   for(int j = 0; j < n; j++) {
	       dp[0][j] = false;
	   }
	   
	   for(int i = 1; i <= n; i++) 
	   {
	       for(int j = 1; j <= sum; j++) 
	       {
	           if(arr[i-1] <= j) {
	               dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
	           } else {
	               dp[i][j]=  dp[i-1][j];
	           }
	       }
	   }
	   
	   int ans = INT_MAX;
	   
	   for(int j = 0; j <= sum; j++) {
	       if(dp[n][j]) {
	           ans = min(ans, abs(2*j - sum));
	       }
	   }
	   return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
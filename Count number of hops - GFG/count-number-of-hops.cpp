//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int dp[100001];
    int MOD = 1000000007;
    
    Solution() {
        memset(dp, -1, sizeof(dp));
        
    }
    
    long long countWays(int n)
    {
        
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (countWays(n - 1)%MOD + countWays(n - 2)%MOD + countWays(n - 3)%MOD)%MOD;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
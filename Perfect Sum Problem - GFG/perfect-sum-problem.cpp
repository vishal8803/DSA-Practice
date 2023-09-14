//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

using ll = long long;

class Solution{

	public:
	int MOD = 1000000007;
	
	ll power(ll x, ll y)
    {
        ll res = 1;
        while (y > 0)
        {
            if (y % 2 == 1)
                res = (res % MOD * x % MOD) % MOD;
            y = y >> 1;
            x = (x % MOD * x % MOD) % MOD;
        }
        return res % MOD;
    }
	
	int calc(vector<int> a, int n, int target, int i, vector<vector<int>> &dp) {
	    if(target == 0) return 1;
	    if(i >= n or target < 0) return 0;
	    
	    if(dp[i][target] != -1) return dp[i][target];
	    
	    int r1 = calc(a, n, target, i + 1, dp);
	    int r2 = calc(a, n, target - a[i], i + 1, dp);
	    
	    return dp[i][target] = (r1%MOD + r2%MOD)%MOD;
	}
	
	int perfectSum(int a[], int n, int target)
	{
	    vector<int> v;
	    int cnt = 0;
	    
	    for(int i = 0; i < n; i++) {
	        if(a[i] == 0) {
	            cnt++;
	        } else {
	            v.push_back(a[i]);
	        }
	    }
        
        vector<vector<int>> dp(v.size() + 1, vector<int>(target + 1, -1));
        ll res = calc(v, v.size(), target, 0, dp);
        ll res2 = power(2, cnt);
        return (res*res2)%MOD;
	}
	  
};



//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{
		vector<vector<long long>> dp(N, vector<long long>(10,0));
		
		dp[0] = {1,1,1,1,1,1,1,1,1,1};
		
		for(int i = 1; i < N; i++){
		    dp[i][0] = dp[i-1][0] + dp[i-1][8];
		    dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][4];
		    dp[i][2] = dp[i-1][2] + dp[i-1][1] + dp[i-1][3] + dp[i-1][5];
		    dp[i][3] = dp[i-1][3] + dp[i-1][2] + dp[i-1][6];
		    dp[i][4] = dp[i-1][4] + dp[i-1][1] + dp[i-1][5] + dp[i-1][7];
		    dp[i][5] = dp[i-1][5] + dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8];
		    dp[i][6] = dp[i-1][6] + dp[i-1][3] + dp[i-1][5] + dp[i-1][9];
		    dp[i][7] = dp[i-1][7] + dp[i-1][4] + dp[i-1][8];
		    dp[i][8] = dp[i-1][8] + dp[i-1][5] + dp[i-1][7] + dp[i-1][9] + dp[i-1][0];
		    dp[i][9] = dp[i-1][9] + dp[i-1][6] + dp[i-1][8];
		}
		
		long long s = 0;
		for(int i = 0; i < 10; i++){
		    s += dp[N-1][i];
		}
		return s;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
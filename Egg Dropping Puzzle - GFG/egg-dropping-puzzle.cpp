//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    Solution() {
        memset(dp, -1, sizeof(dp));    
    }
    
    int eggDrop(int n, int k) 
    {
        if(k == 0) return 0;
        else if(k == 1) return 1;
        else if(n == 1) return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        int res = INT_MAX;
        for(int i = 1; i <= k; i++) {
            int r1 = eggDrop(n-1, i-1);
            int r2 = eggDrop(n, k-i);
            res = min(res, 1 + max(r1 , r2));
        }
        return dp[n][k] = res;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
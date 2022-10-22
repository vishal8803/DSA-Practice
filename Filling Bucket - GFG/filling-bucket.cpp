//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[100001];
    int mod = 1e8;
    
    int calc(int n) {
        if(n == 0) return 1;
        
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (calc(n-1)%mod + calc(n-2)%mod)%mod;
    }
    
    int fillingBucket(int N) {
        memset(dp, -1, sizeof(dp));
        
        return calc(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
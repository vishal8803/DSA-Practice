//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int calc(int price[], int n, vector<int> &dp) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int mx = 0;
        for(int i = 0; i < n; i++) {
            if(i+1 <= n) {
                mx = max(mx, price[i] + calc(price, n - i - 1, dp));
            }
        }
        return dp[n] = mx;
    }
    
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, -1);
        return calc(price, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
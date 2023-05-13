//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countElements(int N, int A[]) {
        vector<int> freq(1e5 + 1, 0);
        
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        for(int i = 0; i < N; i++) {
            freq[A[i]] = 1;
            mn = min(mn, A[i]);
            mx = max(mx, A[i]);
        }
        
        int count = 0;
        for(int i = mn; i <= mx; i++) {
            count += (freq[i] == 0);
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.countElements(N, A) << "\n";
    }
}
// } Driver Code Ends
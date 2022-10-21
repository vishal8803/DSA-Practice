//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int> lmin(n);
        vector<int> rmax(n);
        
        lmin[0] = arr[0];
        rmax[n-1] = arr[n-1];
        
        for(int i = 1; i < n; i++) {
            lmin[i] = min(arr[i], lmin[i-1]);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i+1], arr[i]);
        }
        
        int i = 0;
        int j = 0;
        int mxDiff = -1;
        
        while(i < n and j < n) {
            if(lmin[i] <= rmax[j]) {
                mxDiff = max(mxDiff, j-i);
                j++;
            } else i++;
        }
        
        return mxDiff;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
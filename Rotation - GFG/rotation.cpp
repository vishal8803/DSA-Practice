//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int a[], int n) {
	    int st = 0;
	    int end = n - 1;
	    while(st < end) {
	        int mid = (st + end)/2;
	        if(a[mid] < a[end]) {
	            end = mid;
	        } else {
	            st = mid + 1;
	        }
	    }
	    return st;
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
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
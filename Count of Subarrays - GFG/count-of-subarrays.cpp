//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:

	ll countSubarray(int arr[], int n, int k) {
	    ll count = 0;
	    int i = 0;
	    int j = 0;
	    ll curr = 0;
	    
	    while(j < n) {
	        if(arr[j] <= k) {
	            curr++;
	            j++;
	        } else {
	            count += ((curr)*(curr + 1)) / 2;
	            j++;
	            i = j;
	            curr = 0;
	        }
	    }
	    
	    count += ((curr)*(curr + 1)) / 2LL;
	    ll total = ((long long)n*(long long)(n+1))/2LL;
	    
	    return total - count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
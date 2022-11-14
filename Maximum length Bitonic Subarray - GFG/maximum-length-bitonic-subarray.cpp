//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to find length of longest bitonic
	// subarray
	int bitonic(vector<int> a, int n) {
	    int len = 1;
	    int i = 0;
	    while(i < n - 1) {
	        int count = 0;
	        while(i < n - 1 and a[i] <= a[i+1]) {
	            count++;
	            i++;
	        }
	        while(i < n - 1 and a[i] >= a[i+1]) {
	            count++;
	            i++;
	        }
	        if(i >= n - 1) {
	            count++;
	            len = max(len, count);
	            break;
	            
	        }
	        while(i > 0 and a[i] == a[i-1]) i--;
	       // i++;
	        count++;
	       // cout<<count<<endl;
	        len = max(len, count);
	    }
	    
	    return len;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.bitonic(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // if the element has only one element
	    if(n == 1) return arr[0];
	    
	    int st = 0;
	    int end = n - 1;
	    
	    while(st <= end) {
	        int mid = st + (end - st)/2;
	        
	        if(mid == 0) {
	            if(arr[mid] > arr[mid + 1]) return arr[mid];
	            else {
	                st = mid + 1;
	            }
	        } else if(mid == n - 1) {
	            if(arr[mid] > arr[mid - 1]) return arr[mid];
	            else {
	                end = mid - 1;
	            }
	        } else {
	            if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]) return arr[mid];
	            else if(arr[mid] < arr[mid-1]) {
	                end = mid - 1;
	            } else if(arr[mid] < arr[mid + 1]) {
	                st = mid + 1;
	            }
	        }
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
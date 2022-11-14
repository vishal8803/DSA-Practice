//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> positive;
	    vector<int> negative;
	    
	    for(int i = 0; i < n; i++) {
	        if(arr[i] >= 0) {
	            positive.push_back(arr[i]);
	        } else {
	            negative.push_back(arr[i]);
	        }
	    }
	    
	    int i = 0;
	    int j = 0;
	    int k = 0;
	    
	    while(k < n and i < positive.size() and j < negative.size()) {
	        arr[k++] = positive[i++];
	        if(k < n) {
	            arr[k++] = negative[j++];
	        }
	    }
	    
	    while(k < n and i < positive.size()) {
	        arr[k++] = positive[i++];
	    }
	    
	    while(k < n and j < negative.size()) {
	        arr[k++] = negative[j++];
	    }
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
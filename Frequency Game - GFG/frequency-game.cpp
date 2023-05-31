//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        int elem, freq = INT_MAX;
        for(auto it : mp) {
            if(freq > it.second) {
                elem = it.first;
                freq = it.second;
            } else if(freq == it.second) {
                elem = max(elem, it.first);
            }
        }
        return elem;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends
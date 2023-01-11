//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(), arr.end());
        vector<long long int> v(arr.begin(), arr.end());
        long long int ans = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(v[i] <= v[i-1]) {
                ans += v[i-1] - v[i] + 1;
                v[i] += v[i-1] - v[i] + 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends
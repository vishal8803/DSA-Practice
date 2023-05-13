//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    pair<vector<int>, vector<int>> findTasks(int *arr, int m, int n) {
        vector<int> v;
        vector<int> freq(n + 1, 0);
        
        for(int i = 0; i < m; i++) freq[arr[i]] = 1;
        
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 0) {
                v.push_back(i);
            }
        }
        
        vector<int> v1, v2;
        for(int i = 0; i < v.size(); i += 2) {
            v1.push_back(v[i]);
        }
        for(int i = 1; i < v.size(); i += 2) {
            v2.push_back(v[i]);
        }
        return {v1, v2};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.findTasks(arr, m, n);
        for (auto x: ans.first) {
            cout << x << " ";
        }
        cout << "\n";
        for (auto x: ans.second) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
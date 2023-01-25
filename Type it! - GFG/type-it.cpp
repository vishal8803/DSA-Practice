//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int mx = 0;
        for(int i = 0; i < s.size()/2; i++) {
            if(s.substr(0, i+1) == s.substr(i+1, i+1)) {
                mx = max(mx, i + 1);
            }
        }
        
        if(mx == 0) return s.size();
        
        return s.size() - mx + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
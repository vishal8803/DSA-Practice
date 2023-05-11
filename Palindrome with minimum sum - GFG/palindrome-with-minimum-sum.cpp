//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j) {
            if(s[i] != s[j]) {
                if(s[i] == '?') s[i] = s[j];
                else if(s[j] == '?') s[j] = s[i];
                else return -1;
            }
            i++; j--;
        }
        
        vector<int> temp;
        for(auto &ch : s) {
            if(ch != '?') {
                temp.push_back(ch);
            }
        }
        int n = temp.size();
        int count = 0;
        for(int i = 0; i < n - 1 and i >= 0 ; i++) {
            count += abs(temp[i] - temp[i+1]);
        }
        return count;
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
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
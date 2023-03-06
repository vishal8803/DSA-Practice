//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        string temp = "";
        int num = n;
        while(n > 0) {
            int r = n%2;
            temp += to_string(r);
            n /= 2;
        }
        if(temp.size() <= 2) return num;
        reverse(temp.begin(), temp.end());
        for(int i = 0; i < temp.size() - 2; i++) {
            if(temp[i] == '1' and temp[i+1] == '1' and temp[i+2] == '1') {
                temp[i+2] = '0';
            }
        }
        reverse(temp.begin(), temp.end());
        int p = 1;
        int ans = 0;
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == '1') {
                ans += p;
            }
            p = p*2;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends
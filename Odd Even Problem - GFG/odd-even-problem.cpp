//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string oddEven(string S) {
        int x = 0, y = 0;
        //gwzqhdrxperqar
        vector<int> f(26, 0);
        for(char ch : S) {
            f[ch - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(i%2==0 and f[i]%2) x++;
            else if(i%2==1 and f[i] > 0 and f[i]%2==0)y++;
        }
        
        if((x+y)%2) return "ODD";
        return "EVEN";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.oddEven(S) << endl;
    }
    return 0;
}

// } Driver Code Ends
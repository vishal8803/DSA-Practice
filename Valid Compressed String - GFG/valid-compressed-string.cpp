//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i = 0;
        int j = 0;
        
        while(i < S.size() and j < T.size()) {
            if(S[i] == T[j]) {
                i++;
                j++;
            } else if(T[j] >= '0' and T[j] <= '9') {
                int num = 0;
                while(j < T.size() and T[j] >= '0' and T[j] <= '9'){
                    num = num*10 + (T[j++] - '0');
                }
                while(i < S.size() and num > 0) {
                    i++;
                    num--;
                }
                if(num != 0) return false;
            } else {
                return false;
            }
        }
        
        if(i == S.size() and j == T.size()) return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
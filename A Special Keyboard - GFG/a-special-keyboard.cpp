// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        vector<int> temp(26);
        for(int i = 0; i < S1.length(); i++){
            temp[S1[i]-'a'] = i;
        }
        
        int count = 0;
        int currPos = 0;
        for(int i = 0; i < S2.length(); i++){
            count += abs(currPos-temp[S2[i]-'a']);
            currPos = temp[S2[i]-'a'];
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        vector<int> v;
        
        for(int i = 0; i < N; i++) {
            if(v.size() == 0 or v[v.size()-1] < H[i]) {
                v.push_back(H[i]);
            } else {
                int idx = lower_bound(v.begin(), v.end(), H[i]) - v.begin();
                v[idx] = H[i];
            }
        }
        
        return N - v.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
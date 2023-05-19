//{ Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        unordered_map<int,int> mp1, mp2, mp3, mp4;
        
        int count = 0;
        for(int i = 0; i < N; i++) {
            if(mp1.find(X[i]) != mp1.end() and mp3[X[i]] != Y[i]) {
                count += mp1[X[i]];
            }
            if(mp2.find(Y[i]) != mp2.end() and mp4[Y[i]] != X[i]) {
                count += mp2[Y[i]];
            }
            
            mp1[X[i]]++;
            mp2[Y[i]]++;
            mp3[X[i]] = Y[i];
            mp4[Y[i]] = X[i];
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
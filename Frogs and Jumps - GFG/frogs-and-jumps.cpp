//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
         int cnt = 0; 
        vector<int> leave(leaves + 1); 
        
        for(int i = 0; i < N; i++) 
        {
            int j = frogs[i];
            
            // if it's already true then why we go again 
            if(j <= leaves and leave[j] == true) 
                continue; 
            
            for(; j <= leaves; j += frogs[i])   
            {
                leave[j] = 1; 
            }
        }
        
        for(int i = 1; i <= leaves; i++) 
            if(leave[i] == 0) 
                cnt++; 
            
        return cnt; 
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
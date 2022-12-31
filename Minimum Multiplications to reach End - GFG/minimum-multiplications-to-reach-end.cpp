//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100001, INT_MAX);
        dist[start] = 0;
        
        queue<int> q;
        q.push(start);
        
        int level = 0;
        int mod = 1e5;
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();
                
                if(node == end) return dist[end];
                
                for(int i : arr) {
                    int val = (i%mod*node%mod)%mod;
                    if(dist[val] > 1 + level) {
                        dist[val] = 1 + level;
                        q.push(val);
                    }
                }
                
            }
            level++;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
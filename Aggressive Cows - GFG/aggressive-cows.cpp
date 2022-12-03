//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    int isPossible(vector<int> &stalls, int dist, int k) {
        int cows = 1;
        int last = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - last >= dist) {
                cows++;
                last = stalls[i];
            }
            if(cows >= k) return true;
        }
        
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
        int st = 1;
        int end = 1e9;
        
        int res;
        while(st <= end) {
            int mid = (st + end) / 2;
            if(isPossible(stalls, mid, k)) {
                res = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int calc(vector<vector<int>> &intervals, int target) {
        int st = 0;
        int end = intervals.size() - 1;
        int res = end + 1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            if(intervals[mid][0] >= target) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return res;
    }
    
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            vector<int> interval = intervals[i];
            dp[i] = max(dp[i+1], interval[2] + dp[calc(intervals, interval[1])]);
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends
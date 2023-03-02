//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    pair<int,int> calc(vector<int> v) {
        int mn1=-1, mn2 = -1;
        for(int i = 0; i < v.size(); i++) {
            if(mn1 == -1) {
                mn1 = i;
            }
            else if(v[i] < v[mn1]) {
                mn2 = mn1;
                mn1 = i;
            }
            else if(mn2 == -1) {
                mn2 = i;
            }
             else if(v[i] < v[mn2]) {
                mn2 = i;
            }
        }
        // for(int i : v) cout<<i<<" ";
        // cout<<endl;
        // cout<<mn1<<" "<<mn2<<endl;
        return {mn1, mn2};
    }
    
    
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        int k = costs[0].size();
        if(k == 1 and n != 1) return -1;
        vector<vector<int>> dp(n, vector<int>(k));
        
        dp[0] = costs[0];
        
        for(int i = 1; i < n; i++) {
            pair<int,int> t = calc(dp[i-1]);
            // cout<<t.first<<" "<<t.second<<endl;
            for(int j = 0; j < k; j++) {
                
                if(j == t.first) {
                    dp[i][j] = costs[i][j] + dp[i-1][t.second];
                } else {
                    dp[i][j] = costs[i][j] + dp[i-1][t.first];
                }
            }
        }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends
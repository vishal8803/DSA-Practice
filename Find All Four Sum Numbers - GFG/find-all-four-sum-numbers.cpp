// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int K) {
        int n = arr.size();
        vector<vector<int>> ans;
        
        sort(arr.begin(),arr.end());
        
        int i = 0;
        
        
        while(i < n){
            int j = i + 1;
            
            while(j < n){
                int k = j+1;
                int l = n-1;
                
                int target = K - arr[i] - arr[j];
                
                while(k < l){
                    if(arr[k] + arr[l] == target){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        ans.push_back(temp);
                        
                        while(k<l && arr[k]==temp[2])++k;
                        while(k<l && arr[l]==temp[3])--l;
                    }else if(arr[k] + arr[l] > target){
                        --l;
                    }else{
                        ++k;
                    }
                }
                int temp = arr[j];
                while(j<n && arr[j]==temp)++j;
            }
            int temp = arr[i];
            while(i<n && arr[i]==temp)++i;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
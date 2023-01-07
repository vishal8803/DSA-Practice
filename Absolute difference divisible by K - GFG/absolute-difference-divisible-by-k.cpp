//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        unordered_map<int,int> m;

        for(int i=0;i<n;i++)

        {

            m[arr[i]%k]++;

        }

        long long ans=0,a;

        for(auto it:m)

        {

            if(it.second>1)

            {

                a=it.second;

                ans+=((a*(a-1))/2);

            }

        }

        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends
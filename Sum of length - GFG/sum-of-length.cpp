//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int sumoflength(int arr[], int n) {
        int i = 0;
        int j = 0;
        map<int,int> mp;
        int count = 0;
        while(j < n) {
            mp[arr[j]]++;
            if(mp.size() == j - i + 1) {
                int num = mp.size();
                count += ((num)*(num+1))/2;
                j++;
            } else {
                while( i <= j and mp.size() != j - i + 1) {
                    mp[arr[i]]--;
                    if(mp[arr[i]] == 0) mp.erase(arr[i]);
                    i++;
                }
                int num = mp.size();
                count += ((num)*(num+1))/2;
                j++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.sumoflength(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
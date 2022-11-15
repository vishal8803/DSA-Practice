//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        map<int,int> mp;
        int i = 0;
        int j = 0;
        int len = 0;
        
        while(j < N) {
            mp[arr[j]]++;
            int val1 = (mp.begin()->first);
            int val2 = (mp.rbegin()->first);
            
            if(val2 - val1 <= 1) {
                len = max(len, j - i + 1);
                j++;
            } else {
                while(i <= j) {
                    int val1 = (mp.begin()->first);
                    int val2 = (mp.rbegin()->first);
                    
                    if(val2 - val1 > 1) {
                        mp[arr[i]]--;
                        if(mp[arr[i]]==0) mp.erase(arr[i]);
                        i++;
                    }
                    else break;
                }
                len = max(len, j- i + 1);
                j++;
            }
        }
        
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
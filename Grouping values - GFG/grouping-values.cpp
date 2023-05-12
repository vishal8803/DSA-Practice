//{ Driver Code Starts
// Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(int N, int arr[], int K){
        map<int, int> mp;
        for(int i = 0; i < N; i++) {
            mp[arr[i]]++;
        }
        int mx = 0;
        for(auto &it : mp) {
            int f = it.second;
            mx = max(mx, f/2 + f%2);
        }
        return mx <= K;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cin>>K;
        
        Solution ob;
        cout<<ob.isPossible(N, arr, K)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
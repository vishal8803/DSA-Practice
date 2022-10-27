//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void solve(int arr[], map<int,int> &mp, vector<int> &ans, int st, int end, int inst, int inend) {
        if(st > end) return;
        if(st == end) {
            ans.push_back(arr[st]);
            return;
        }
        
        int pos = mp[arr[st]];
        int left = pos - inst;
        int right = end - pos;
        solve(arr, mp, ans, st + 1, st + left, inst, inst + pos-1);
        solve(arr, mp, ans, st + left + 1, end, pos+1, inend);
    }
    
    vector<int> leafNodes(int arr[],int N) {
        vector<int> ans;
        vector<int> pos;
        for(int i = 0; i < N; i++) {
            pos.push_back(arr[i]);
        }
        sort(pos.begin(), pos.end());
        map<int,int> mp;
        
        for(int i = 0; i < N; i++) {
            mp[pos[i]] = i;
        }
        
        solve(arr, mp, ans, 0, N - 1, 0, N - 1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
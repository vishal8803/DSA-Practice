// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool calc(int N, int arr[], int i, int target){
        if(target==0)
            return true;
        
        if(i>=N || target<0)
            return false;
        
        return calc(N,arr,i+1,target-arr[i]) || calc(N,arr,i+1,target);
    }
    int equalPartition(int N, int arr[])
    {
        int s = 0;
        for(int i = 0; i < N; i++)
            s += arr[i];
            
        if(s%2)
            return 0;
        
        int target = s/2;
        
        return calc(N,arr,0,target);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
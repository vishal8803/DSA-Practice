// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        long long int s1 = 0;
        long long int s2 = 0;
        for(int i = 0; i < n; i+=2){
            s1 = s1*10 + arr[i];
        }
        for(int i = 1; i < n; i+=2){
            s2 = s2*10 + arr[i];
        }
        long long int r1 = s1 + s2;
        return r1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
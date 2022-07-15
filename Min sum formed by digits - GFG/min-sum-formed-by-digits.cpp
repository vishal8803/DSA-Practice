// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        long long int num1 = 0;
        long long int num2 = 0;
        
        sort(arr,arr+n);
        
        for(int i = 0; i < n; i+=2){
            num1 = num1*10 + arr[i];
            if(i+1<n){
                num2 = num2*10 + arr[i+1];
            }
        }
        
        long long int ans = num1 + num2;
        
        return ans;
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
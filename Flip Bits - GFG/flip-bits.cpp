//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int arr[], int n)
    {
        int sum=0,cs=0;
        
        for(int i=0; i<n; i++){
            if(arr[i])
                cs+=-1;
            else
                cs+=1;
            
            sum = max(sum,cs);
            if(cs<0)
                cs=0;
        }
        
        for(int i=0; i<n; i++)
        {
            if(arr[i])
                sum++;
        }
        return sum;
    }
};




//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
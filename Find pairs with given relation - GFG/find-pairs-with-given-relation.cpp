//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 
#define ll long long

class Solution
{
  public:
    int findPairs(int arr[], int n)
    {
       map<int,int> mp;
       loop(i, 0, n) {
           loop(j, i+1, n) {
               mp[arr[i]*arr[j]]++;
               if(mp[arr[i]*arr[j]] >= 2) return 1;
           }
       }
       return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;    
       cout<<ob.findPairs(arr, n)<<endl;        
    }
  
    return 0;
}
// } Driver Code Ends
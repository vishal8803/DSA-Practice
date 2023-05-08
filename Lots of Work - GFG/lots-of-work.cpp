//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    bool isPossible(long Arr[], long mid, long n, long m) {
        long count = 0;
        long cnt = 0;
        for(int i = 0; i < n; i++) {
            if(count + Arr[i] <= mid) {
                count += Arr[i]; 
            } else {
                count = Arr[i];
                cnt++;
            }
        }
        cnt++;
        return cnt <= m;
    }
    
    long  minAmountOfTime(long Arr[], long n, long m)
    {
        long st = *max_element(Arr, Arr+n);
        long end = 0;
        
        for(int i = 0; i < n; i++) {
            end += Arr[i];
        }
        
        long res;
        while(st <= end) {
            long mid = st + (end - st) / 2;
            if(isPossible(Arr, mid, n, m)) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long  n,m;
        cin >> n >>m;
        long Arr[n];
        for(long i=0;i<n;i++)cin>>Arr[i];
        Solution ob;
        cout<<ob.minAmountOfTime(Arr,n,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    bool isSetBit(long long int num, int pos) {
        if((num&(1<<pos))) return true;
        
        return false;
    }
    
    vector<long long int> twoOddNum(long long int arr[], long long int N)  
    {
        vector<long long int> ans;
        
        long long int xr = 0;
        
        for(long long int i = 0; i < N; i++) {
            xr = xr^arr[i];
        }
        
        long long int temp = xr;
        int count = 0;
        
        while(temp > 0) {
            if(temp&1) {
                break;
            }
            temp >>=1;
            count++;
        }
        
        long long int bucket1 = 0;
        
        for(long long int i = 0; i < N; i++) {
            if(isSetBit(arr[i], count)) {
                bucket1 = bucket1 ^ arr[i];
            } 
        }
        
        ans = {max(bucket1, xr^bucket1), min(bucket1, xr^bucket1)};
        
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
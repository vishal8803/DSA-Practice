// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int search(vector<int>& a, int st, int end, int target){
        int res = -1;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(a[mid]<target){
                res = mid;
                st = mid + 1;
            }else{
                end = mid - 1; 
            }
        }
        
        return res;
    }
    
    vector<int> farNumber(int N,vector<int> Arr){
        vector<int> prev(N);
        
        int mn = Arr[N-1];
        
        for(int i = N-1; i>=0; i--){
            mn = min(mn,Arr[i]);
            prev[i] = mn;
        }
        
        
        vector<int> ans;
        
        for(int i = 0; i < N; i++){
            ans.push_back(search(prev,i+1,N-1,Arr[i]));
        }
        
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends
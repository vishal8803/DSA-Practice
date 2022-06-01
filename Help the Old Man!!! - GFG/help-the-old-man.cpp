// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void calc(int N, int i, int j, int k, int &count, int n, int &fi, int &fj){
        
        if(N==0){
            return;
        }
        
        calc(N-1, i,k,j,count,n,fi,fj);
        count++;
        if(count==n){
            fi=i;
            fj=k;
        }
        calc(N-1, j,i,k,count,n,fi,fj);
    }
    vector<int> shiftPile(int N, int n){
        int count = 0;
        int fi,fj;
        calc(N,1,2,3,count,n,fi,fj);
        return {fi,fj};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
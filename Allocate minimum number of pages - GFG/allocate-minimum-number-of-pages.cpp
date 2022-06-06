// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossibleToAllocate(int A[], int N, int M, int maxPages){
        int count = 1;
        int pages = 0;
        
        
        for(int i = 0; i < N; i++){
            pages += A[i];
            
            if(pages > maxPages){
                count++;
                pages = A[i];
            }
            
            if(count > M)
                return false;
        }
        
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int st = *max_element(A,A+N);
        
        int end = 0;
        
        for(int i = 0; i < N; i++){
            end += A[i];
        }
        
        int ans = -1;
        
        while(st<=end){
            int mid = (st+end)/2;
            if(isPossibleToAllocate(A,N,M,mid)){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
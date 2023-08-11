//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int v[], int n){
	    if(n == 1) {
            return v[0];
        }

        int st = 0;
        int end = n - 1;

        while(st <= end) {
            int mid = (st + end) / 2;
            if(v[mid] == v[mid^1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return (v[st]);
	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends
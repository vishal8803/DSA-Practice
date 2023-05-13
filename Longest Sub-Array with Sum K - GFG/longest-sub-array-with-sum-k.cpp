//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 
#define ll long long

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<int,int> mp;
        int len = 0;
        int sum = 0;
        
        mp[0] = -1;
        
        loop(i, 0, N) {
            sum += A[i];
            if(mp.find(sum - K) != mp.end()) {
                len = max(len, i - mp[sum-K]);
            } 
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
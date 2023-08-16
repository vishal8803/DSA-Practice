//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Initial template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    long long int m = 1000000007;
    int findCatalan(int n) 
    {
        //code here
        int dp[n+1];
        dp[0] = dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            long long int cat = 0;
            
            int k = 0, j = i-1;
            while(k<=j){
                if(k == j){
                    cat = ((cat % m)+((dp[k]% m) * (dp[j]% m)) % m) % m ;
                }else{
                    cat = ((cat % m)+ (((dp[k]% m) * (dp[j]% m)) + ((dp[j]% m) * (dp[k]% m))) % m)% m;
                }
                k++;
                j--;
            }
            dp[i] = cat;
        }
        return dp[n];
    }
};




//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends
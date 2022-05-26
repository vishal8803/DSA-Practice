// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int countCuts(int len, int x, int y, int z, vector<int> &dp)
    {
        if(len==0)
            return 0;
            
        
            
        if(dp[len] != -1)
            return dp[len];
        
        int r1 =  INT_MIN;
        if(len>=x){
            r1 = countCuts(len-x,x,y,z,dp);
        }
        
        int r2 = INT_MIN;
        if(len>=y){
            r2 = countCuts(len-y,x,y,z,dp);
        }
        
        int r3 = INT_MIN;
        if(len>=z){
            r3 = countCuts(len-z,x,y,z,dp);
        }
        
        
        return dp[len] = 1 + max(r1,max(r2,r3));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int a = countCuts(n,x,y,z,dp);
        if(a<0)
            return 0;
        return a;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
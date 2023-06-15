//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string str) {
        // code here
         int n = str.length();
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; i++,j++){
                if(g==0){
                    dp[i][j]=true;
                }else if(g==1){
                    if(str[i]==str[j]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    if(str[i]==str[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        int len = 0;
        string ans = "";
        int ai,aj;
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; i++,j++){
                if(j-i+1>len && dp[i][j]){
                    len = j-i+1;
                    ai=i;
                    aj=j;
                }
            }
        }
        return str.substr(ai,len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
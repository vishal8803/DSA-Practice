//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            int p = 1;
            int ans = 0;
            
            reverse(begin(s), end(s));
            for(char ch : s) {
                if(ch == '1') {
                    ans = (ans%m + p%m)%m;
                }
                p = (p%m * 2%m)%m;
            }
            
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
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends
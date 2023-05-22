//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        if(n == 1) return 0;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            st.push(i);
        }
        
        while(st.size() > 1) {
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            if(M[t1][t2] == 1) {
                st.push(t2);
            } else {
                st.push(t1);
            }
        }
        
        int t = st.top();
        for(int i = 0; i < n; i++) {
            if(M[t][i] != 0) return -1;
            if(i != t and M[i][t] != 1) return -1;
        }
        return t;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
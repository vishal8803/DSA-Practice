//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<vector<int>> v(32, vector<int>(N, 0));
            
            for(auto q : U) {
                int l = q[0] - 1;
                int r = q[1] - 1;
                int num = q[2];
                
                for(int i = 0; i < 32; i++) {
                    int bit = ((num>>i)&1);
                    if(bit) {
                        v[i][l] += 1;
                        if(r + 1 < N) {
                            v[i][r+1] -= 1;
                        }
                    }
                }
            }
            
            for(int i = 0; i < 32; i++) {
                for(int j = 1; j < N; j++) {
                    v[i][j] += v[i][j-1];
                }
            }
            
            vector<int> ans(N);
            for(int i = 0; i < N; i++) {
                int num = 0;
                for(int j = 0; j < 32; j++) {
                    if(v[j][i] > 0) {
                        num = num | (1<<j);
                    }
                }
                ans[i] = num;
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
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
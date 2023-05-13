//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 
#define ll long long

class Solution{
public:
    int distinct(vector<vector<int>> M, int N)
    {
        map<int,int> mp;
        loop(i, 0, N) {
            if(mp[M[0][i]] == 0)
                mp[M[0][i]]++;
        }
        
        
        loop(i, 1, N) {
            loop(j, 0, N) {
                if(mp[M[i][j]] > 0 and mp[M[i][j]] == i) mp[M[i][j]]++;   
            }
        }
        
        int count = 0;
        for(auto it : mp) {
            if(it.second >= N) count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
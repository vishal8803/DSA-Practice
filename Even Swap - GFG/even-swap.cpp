//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            vector<int> ans;
            
            int i = 0;
            while(i < n) {
                vector<int> temp;
                int r = a[i]%2;
                while(i < n and a[i]%2 == r) {
                    temp.push_back(a[i++]);
                }
                sort(temp.begin(), temp.end(), greater<int>());
                for(int i : temp) ans.push_back(i);
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
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
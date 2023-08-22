//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> vec;
        vector<int> vec1;
        int maxi=INT_MIN;
        int maxi1=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            int sum1=0;
            for(int j=0;j<n;j++){
                sum+=matrix[i][j];
                sum1+=matrix[j][i];
            }
            vec.push_back(sum);
            vec1.push_back(sum1);
            maxi=max(maxi,sum);
            maxi1=max(maxi1,sum1);
        }
        int cnt=0;
        int cnt1=0;
        for(int i=0;i<vec.size();i++){
            cnt+=abs(maxi-vec[i]);
            cnt1+=abs(maxi1-vec1[i]);
        }
        return max(cnt,cnt1);
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
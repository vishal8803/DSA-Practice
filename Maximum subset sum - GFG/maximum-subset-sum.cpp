//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    int dp[100001][2];
    long long calc(vector<int> &v, int i, int N, int prev) {
        if(i == v.size()) return 0;
        
        if(prev != -1 and dp[i][prev]!= -1) return dp[i][prev]; 
        
        if(prev == -1){
            long long r1 = max((long long)v[i] + calc(v, i + 1, N, 1), calc(v, i  +1, N, 0));
            long long r2 = (long long)v[i] + calc(v, i + 1, N, 1);
            return max(r1, r2);
        }
        else if(prev==1) {
            return dp[i][prev] = max((long long)v[i] + calc(v, i + 1, N, 1), calc(v, i  +1, N, 0));
        } else {
            return dp[i][prev] = (long long)v[i] + calc(v, i + 1, N, 1);
        }
    }
    
    long long findMaxSubsetSum(int N, vector<int> &A) {
        memset(dp, -1, sizeof(dp));
        return calc(A, 0, N, -1);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
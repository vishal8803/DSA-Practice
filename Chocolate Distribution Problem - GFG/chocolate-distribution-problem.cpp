//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        int i = m-1;
        int j = 0;
        long long profit = LONG_MAX;
        for(int i = m-1; i<n; i++){
            profit = min(profit,a[i]-a[j]);
            j++;
        }
        return profit;
    }   
};



//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
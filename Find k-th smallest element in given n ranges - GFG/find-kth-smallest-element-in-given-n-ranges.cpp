//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int> kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(begin(range), end(range));
        vector<vector<int>> intervals;
        vector<int> interval = range[0];
        
        for(int i = 1; i < n; i++) {
            if(range[i][0] <= interval[1]) {
                interval[0] = min(interval[0], range[i][0]);
                interval[1] = max(interval[1], range[i][1]);
            } else {
                intervals.push_back(interval);
                interval = range[i];
            }
        }
        
        intervals.push_back(interval);
        vector<int> ans;
        
        for(int k : queries) {
            int count = 0;
            bool flag = false;
            for(auto it : intervals) {
                int num = it[1] - it[0] + 1;
                if(count + num < k) {
                    count += num;
                } else {
                    flag = true;
                    int diff = k - count;
                    ans.push_back(it[0] + diff -1);
                    break;
                }
            }
            if(!flag) {
                ans.push_back(-1);
            }
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
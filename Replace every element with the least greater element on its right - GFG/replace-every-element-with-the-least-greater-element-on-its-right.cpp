//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans;
        set<int> st;
        st.insert(arr[n-1]);
        ans.push_back(-1);
        
        for(int i = n - 2; i >= 0; i--) {
            auto it = st.lower_bound(arr[i] + 1);
            if(it != st.end()) {
                ans.push_back(*it);
            }
            else ans.push_back(-1);
            st.insert(arr[i]);
        }
        
        reverse(ans.begin(), ans.end());
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
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends
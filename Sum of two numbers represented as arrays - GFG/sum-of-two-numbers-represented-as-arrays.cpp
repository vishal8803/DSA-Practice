// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    reverse(a.begin(), a.end());
	    reverse(b.begin(), b.end());
	    
	    int i = 0, j = 0;
	    
	    int carry = 0;
	    
	    vector<int> ans;
	    
	    while(i<a.size() || j<b.size() || carry){
	        int sum = 0;
	        
	        if(i<a.size()){
	            sum += a[i];
	            i++;
	        }
	        
	        if(j<b.size()){
	            sum += b[j];
	            j++;
	        }
	        
	        sum += carry;
	        
	        ans.push_back(sum%10);
	        carry = sum/10;
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
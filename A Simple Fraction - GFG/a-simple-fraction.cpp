//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int n, int d) {
	    map<int,int> mp;
	    string ans = "";
	    int q = n/d;
	    int r = n%d;
	    ans += to_string(q);
	    if(r==0) return ans;
	    ans += ".";
	    while(r != 0) {
	        if(mp.find(r) != mp.end()) {
	            int pos = mp[r];
	            string t1 = ans.substr(0, pos);
	            return t1 + "(" + ans.substr(pos) + ")";
	        } else {
	            mp[r] = ans.size();
    	        r = r*10;
    	        q = r/d;
    	        r = r%d;
    	        ans += to_string(q);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
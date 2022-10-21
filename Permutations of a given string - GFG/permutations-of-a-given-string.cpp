//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void calc(string s, set<string> &st, string temp) {
	        if(s.size() == 0) {
	            st.insert(temp);
	            return;
	        }
	        
	        string final = "";
	        
	        for(int i = 0; i < s.size(); i++) {
	            calc(s.substr(0, i) + s.substr(i+1), st, temp + s[i]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    set<string> st;
		    calc(S, st, "");
		    vector<string> v;
		    
		    for(auto it : st) {
		        v.push_back(it);
		    }
		    
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void calc(string S, string temp, vector<string> &ans) {
        if(S.size() == 0) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < S.size(); i++) {
            string ns = S.substr(0, i) + S.substr(i + 1);
            calc(ns, temp + S[i], ans);
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        calc(S, "", ans);
        sort(begin(ans), end(ans));
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
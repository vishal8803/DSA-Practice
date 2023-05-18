//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:	
	bool sameFreq(string s)
	{
	    map<char,int> mp;
	    for(char ch : s) {
	        mp[ch]++;
	    }
	    map<int,int> mp2;
	    for(auto it : mp) {
	        mp2[it.second]++;
	    }
	    if(mp2.size() == 1) return true;
	    for(auto it : s) {
	        int f = mp[it];
	        mp2[f]--;
	        if(mp2[f] == 0) {
	            mp2.erase(f);
	        }
	        if(f>1) mp2[f-1]++;
	        if(mp2.size()== 1) return true;
	        
	        if(f>1) mp2[f-1]--;
	        if(mp2[f-1] == 0) {
	            mp2.erase(f-1);
	        }
	        mp2[f]++;
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
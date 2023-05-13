//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        map<pair<int,int>, int> mp;
        int zero = 0;
        int one = 0;
        int two = 0;
        
        long long count = 0;
        
        mp[{0,0}] = 1;
        
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '0') zero++;
            else if(str[i] == '1') one++;
            else two++;
            
            count += mp[{one - zero, two - one}];
            mp[{one - zero, two - one}]++;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends
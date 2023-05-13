//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 
#define ll long long

class Solution{
public:	

	int countSubstringWithEqualEnds(string s)
	{
	    vi freq(26, 0);
	    loop(i, 0, len(s)) freq[s[i] - 'a']++;
	    int count = 0;
	    
	    loop(i, 0, 26) count += (freq[i]*(freq[i]+1))/2;
	    
	    return count;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   	    Solution ob;

   		cout << ob.countSubstringWithEqualEnds(str) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
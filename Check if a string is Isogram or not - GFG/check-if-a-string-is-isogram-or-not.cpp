//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define all(a) a.begin(),a.end()
#define loop(i,a,b) for (int i = a; i < b; i++)
#define len(a) a.size()
#define vi vector<int> 

class Solution
{
    public:
    
    bool isIsogram(string s)
    {
        vi freq(26, 0);
        
        loop(i, 0, len(s)) {
            freq[s[i] - 'a']++;
            if(freq[s[i] - 'a'] > 1) return false;
        }
        
        return true;
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
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
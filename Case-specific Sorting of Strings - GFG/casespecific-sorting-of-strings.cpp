//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string t = "";
        string s = "";
        
        for(char ch : str) {
            if(islower(ch)) {
                t += ch;
            } else {
                s += ch;
            }
        }
        
        sort(t.begin(), t.end());
        sort(s.begin(), s.end());
        
        int j = 0, k = 0;
        
        for(int i = 0; i < n; i++) {
            if(islower(str[i])) {
                str[i] = t[j++];
            } else {
                str[i] = s[k++];
            }
        }
        
        return str;
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
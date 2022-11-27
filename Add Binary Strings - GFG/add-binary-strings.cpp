//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    int i = 0;
	    while(i < A.size() and A[i] == '0') i++;
	    A = A.substr(i);
	    i = 0;
	    while(i < B.size() and B[i] == '0') i++;
	    B = B.substr(i);
	    reverse(A.begin(), A.end());
	    reverse(B.begin(), B.end());
	    
	    string ans = "";
	    int  j = 0, carry = 0; 
	    i = 0;
	    while(i < A.size() or j < B.size() or carry > 0) {
	        int sum = 0;
	        if(i < A.size()) {
	            sum += (A[i++] - '0');
	        }
	        if(j < B.size()) {
	            sum += (B[j++] - '0');
	        }
	        
	        sum += carry;
	        ans += to_string(sum%2);
	        carry = sum/2;
	    }
	    
	    reverse(ans.begin(), ans.end());
	    i = 0;
	    while(i < ans.size() and ans[i] == '0') i++;
	    ans = ans.substr(i);
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
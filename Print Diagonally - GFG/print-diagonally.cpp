//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		vector<int> ans;
		
		for(int g = 0; g < n; g++) {
		    for(int i = 0, j = g; j >= 0 and i < n; i++, j--){
		        ans.push_back(A[i][j]);
		    }
		}
		
		for(int i = 1; i < n; i++) {
		    for(int k = i, j = n - 1; j >= 0 and k < n; j--, k++) {
		        ans.push_back(A[k][j]);
		    }
		}
		
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
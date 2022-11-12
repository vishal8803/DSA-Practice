//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int calc(string s, int k, char ch) {
	        int mx = 0;
	        int len = 0;
	        int i = 0;
	        int j = 0;
	        int count = 0;
	        
	        while(j < s.size()) {
	            if(s[j] == ch) count++;
	            
	            int rem = j-i+1 - count;
	            
	            if(rem <= k) {
	                mx = max(mx, j-i+1);
	                j++;
	            } else {
	                while(i <= j and j-i+1-count > k) {
	                    if(s[i]==ch) count--;
	                    i++;
	                }
	                if(i <= j and j-i+1 - count <= k) mx = max(mx, j-i+1);
	                j++;
	            }
	        }
	        
	        return mx;
	    }
	    
		int characterReplacement(string s, int k){
		     int mx = INT_MIN;
		     vector<int> f(26,0);
		     
		     for(char ch : s) {
		         f[ch-'A']++;
		     }
		     
		     for(int i = 0; i < 26; i++) {
		         if(f[i] > 0)
		            mx = max(mx, calc(s, k, 'A' + i));
		     }
		     
		     return mx;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
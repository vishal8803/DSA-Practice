// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans = "";
		    queue<char> q;
		    vector<int> freq(26,0);
		    
		    for(char ch : A){
		        freq[ch-'a']++;
		        q.push(ch);
		        bool flag = false;
		        
		        while(q.size()>0 && freq[q.front()-'a']!=1){
		            q.pop();
		        }
		        
		        if(q.size()==0){
		            ans += '#';
		        }else{
		            ans += q.front();
		        }
		        
		    }
		    
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
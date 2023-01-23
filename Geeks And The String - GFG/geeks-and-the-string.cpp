//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<char> st;
        
        for(char ch : s) {
            if(st.size() == 0) {
                st.push(ch);
            } else {
                if(st.top() == ch) {
                    st.pop();
                } else {
                    st.push(ch);
                }
            }
        }
        
        string ans = "";
        while(st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        
        if(ans.size() == 0) return "-1";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
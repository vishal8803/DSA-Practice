//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        stack<pair<char,int>> st;
        
        for(char &ch : s) {
            if(st.size() == 0) {
                st.push({ch, 1});
            } else {
                if(st.top().first == ch) {
                    auto it = st.top();
                    st.pop();
                    int count = it.second;
                    st.push({ch, count + 1});
                } else {
                    st.push({ch, 1});
                }
                if((st.top().second%k) == 0) {
                    st.pop();
                }
            }
            
        }
        
        string ans = "";
        
        
        
        while(st.size() > 0) {
            char ch = st.top().first;
            int f = st.top().second;
            st.pop();
            if(f%k == 0) continue;
            while(f--) {
                ans += ch;
            }
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends
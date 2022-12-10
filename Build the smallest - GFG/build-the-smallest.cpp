//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    stack<char> st;
    for(char ch : num) {
        while(st.size() > 0 and st.top() > ch and k > 0) {
            st.pop();
            k--;
        } 
        st.push(ch);
    }
    
    while(k > 0 and st.size() > 0 ) {
        st.pop();
        k--;
    }
    
    
    string ans = "";
    while(st.size() > 0) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    
    int idx = 0;
    while(idx < ans.size() and ans[idx] == '0') idx++;
    
    string res = ans.substr(idx);
    if(res == "" ) return "0";
    return res;
}
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        
        string ans = "";
        ans += str[0];
        if(str.size() == 1 or str[0] == str[1]) {
            string res = "";
            res += str[0];
            res += str[0];
            return res;
        }
        for(int i = 1; i < str.size(); i++) {
            if(ans[ans.size()-1] >= str[i]) {
                ans += str[i];
            } else break;
        }
        
        string temp = ans;
        reverse(begin(temp), end(temp));
        return ans + temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void calc(int n, vector<string> &ans, string s, string temp, string ansS, int i, set<string> &st,bool f){
        if(i==s.length()){
            if(f)
                ans.push_back(ansS);
            return;
        }
        
        temp += s[i];
        // cout<<temp<<endl;
        
        if(st.find(temp) != st.end()){
            if(i+1==s.length())
                calc(n,ans,s,"",ansS+temp,i+1,st, true);
            else
                calc(n,ans,s,"",ansS+temp+" ",i+1,st, true);
        }
        calc(n,ans,s,temp,ansS,i+1,st, false);
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        set<string> st;
        for(string s : dict){
            st.insert(s);
        }
        vector<string> ans;
        
        calc(n,ans,s,"","",0,st,false);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
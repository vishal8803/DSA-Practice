// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void calc(set<string> &st, vector<string> &ans, string s, int i, string temp){
        if(i==s.length()){
            ans.push_back(temp);
            return;
        }
        string t = "";
        for(int j = i; j < s.length(); j++){
            t += s[j];
            if(st.find(t) != st.end()){
                if(temp=="")
                calc(st,ans,s,j+1,temp + t);
                else
                calc(st,ans,s,j+1,temp + " " + t);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        set<string> st;
        for(auto it : dict){
            st.insert(it);
        }
        calc(st,ans,s,0,"");
        sort(ans.begin(),ans.end());
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
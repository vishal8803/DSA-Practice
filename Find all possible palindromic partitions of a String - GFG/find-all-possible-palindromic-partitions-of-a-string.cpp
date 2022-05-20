// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.length()-1;
        
        while(i<=j){
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
    
    void calc(string s, vector<vector<string>> &ans, vector<string> temp){
        if(s.length()==0){
            bool flag = true;
            
            for(string s : temp){
                if(isPalindrome(s)==false){
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                ans.push_back(temp);
            
            return;
        }
        
        string t = "";
        
        for(int i = 0; i < s.length(); i++){
            t = t + s[i];
            temp.push_back(t);
            calc(s.substr(i+1),ans,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        calc(S,ans,{});
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
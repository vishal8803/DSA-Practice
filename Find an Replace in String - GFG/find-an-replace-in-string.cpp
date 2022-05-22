// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        map<int,string> mp;
        map<int,int> mp2;
        
        
        
        for(int i = 0; i < Q; i++){
            int idx = index[i];
            string source = sources[i];
            
            int j = 0;
            for(j = 0; j < source.length() && idx + j < S.length(); j++){
                if(source[j] != S[idx+j]){
                    break;
                }
            }
            if(j==source.length()){
                mp[idx] = targets[i];
            }
            
            mp2[idx] = source.length();
        }
        
        string ans = "";
        
        for(int i = 0; i < S.length(); i++){
            if(mp.find(i) != mp.end()){
                ans += mp[i];
                i+=mp2[i]-1;
            }else{
                ans += S[i];
            }
        }
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
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends
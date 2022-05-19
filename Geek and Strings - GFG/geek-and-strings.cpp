// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct Trie{
        Trie* node[26];
        int cp = 0;
    };
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        Trie* root = new Trie();
        
        for(int i = 0; i < N; i++){
            string word = li[i];
            Trie* temp = root;
            for(int j = 0; j < word.length(); j++){
                if(temp->node[word[j]-'a']==NULL){
                    temp->node[word[j]-'a'] = new Trie();
                }
                temp = temp->node[word[j]-'a'];
                temp->cp = temp->cp + 1;
            }
        }
        vector<int> ans;
        for(int i = 0; i < Q; i++){
            string word = query[i];
            int count = 0;
            Trie* temp = root;
            bool flag = true;
            for(int j = 0; j < word.length(); j++){
                if(temp->node[word[j]-'a']==NULL){
                    flag = false;
                    break;
                }
                temp = temp->node[word[j]-'a'];
                count = temp->cp;
            }
            if(flag)
            ans.push_back(count);
            else
            ans.push_back(0);
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}  // } Driver Code Ends
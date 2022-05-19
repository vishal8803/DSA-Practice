// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}

// } Driver Code Ends


/*You are required to complete this method */
struct Trie {
    Trie* node[26];
};

int countDistinctSubstring(string s)
{
    Trie* root = new Trie();
    int count = 0;
    
    for(int i = 0; i < s.length(); i++){
        Trie* temp = root;
        for(int j = i; j < s.length(); j++){
            if(temp->node[s[j]-'a']==NULL){
                count++;
                temp->node[s[j]-'a'] = new Trie();
            }
            temp = temp->node[s[j]-'a'];
        }
    }
    return count + 1;
}
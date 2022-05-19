// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    struct Trie{
        Trie* node[26];
        int cp = 0;
    };
    
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie* root = new Trie();
        for(int i = 0; i < n; i++){
            Trie* temp = root;
            string word = arr[i];
            for(int i = 0; i < word.length(); i++){
                if(temp->node[word[i]-'a']==NULL){
                    temp->node[word[i]-'a'] = new Trie();
                }
                temp = temp->node[word[i]-'a'];
                temp->cp = temp->cp + 1;
            }
            
        }
        
        vector<string> ans;
        for(int i = 0; i < n; i++){
            string word = arr[i];
            Trie* temp = root;
            string res = "";
            for(int j = 0; j < word.length(); j++){
                res += word[j];
                temp = temp->node[word[j]-'a'];
                if(temp->cp>=2)
                    continue;
                else
                    break;
            }
            ans.push_back(res);
        }
        
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends
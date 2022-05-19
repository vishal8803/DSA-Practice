// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    struct Trie{
        Trie* node[26];
        int cp = 0; 
    };
    
    int klengthpref(string arr[], int n, int k, string str){    
        
        Trie* root = new Trie();
        
        for(int i = 0; i < n; i++){
            string word = arr[i];
            Trie* temp = root;
            for(int j = 0; j < word.length(); j++){
                if(temp->node[word[j]-'a']==NULL){
                    temp->node[word[j]-'a'] = new Trie();
                }
                
                temp = temp->node[word[j]-'a'];
                temp->cp = temp->cp + 1;
            }
        }
        
        int count = 0;
        Trie* temp = root;
        
        if(k>str.length())
            return count;
            
        for(int i = 0; i < k; i++)
        {
            if(temp->node[str[i]-'a']==NULL)
                return 0;
            
            temp = temp->node[str[i]-'a'];
        }
        
        return temp->cp;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
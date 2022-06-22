// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    struct Node{
        Node* children[26];
        int cp = 0;
    };
    
    vector<string> findPrefixes(string arr[], int n)
    {
        Node* root = new Node();
        
        for(int i = 0; i < n; i++){
            string s = arr[i];
            Node* temp = root;
            
            for(char ch : s){
                if(temp->children[ch-'a']==NULL){
                    temp->children[ch-'a']= new Node();
                }
                temp = temp->children[ch-'a'];
                temp->cp = temp->cp + 1;
            }
        }
        
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            string s = arr[i];
            Node* t = root;
            string k = "";
            
            for(char ch : s){
                k += ch;
                t=t->children[ch-'a'];
                if(t->cp>=2){
                    continue;
                }else{
                    break;
                }
            }
            ans.push_back(k);
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
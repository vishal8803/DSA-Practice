// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    struct Node{
        Node* children[26];
        bool isLeaf = false;
    };
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Node* root=  new Node();
        for(int i = 0; i < n; i++){
            Node* temp = root;
            for(char ch : contact[i]){
                if(temp->children[ch-'a']==NULL){
                    temp->children[ch-'a'] = new Node();
                }
                temp = temp->children[ch-'a'];
            }
            temp->isLeaf = true;
        }
        
        string temp = "";
        vector<vector<string>> ans;
        
        for(char ch : s){
            temp += ch;
            Node *t = root;
            bool flag = true;
            for(char c : temp){
                if(t->children[c-'a']==NULL){
                    flag = false;
                    break;
                }
                t = t->children[c-'a'];
            }
            if(!flag){
                ans.push_back({"0"});
            }else{
                set<string> e;
                for(int i = 0; i < n; i++){
                    if(contact[i].substr(0,temp.length())==temp){
                        e.insert(contact[i]);
                    }
                }
                vector<string> r;
                for(auto it = e.begin(); it != e.end(); it++){
                    r.push_back(*it);
                }
                ans.push_back(r);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
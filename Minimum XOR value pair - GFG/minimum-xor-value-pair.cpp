// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Trie{
 public:
 Trie* next[2];
 Trie(){
     next[0]=next[1] = NULL;
 }
   
};

void insert(Trie* root, int n){
   for(int i=31;i>=0;i--){
       int bit = (n>>i)&1;
       
       if(root->next[bit]==NULL){
           Trie* t = new Trie();
           root->next[bit] = t;
       }
       
       root = root->next[bit];
       
       
   }
}

int get(Trie* root, int n){
   int ans =0;
   
   for(int i=31;i>=0;i--){
       int bit = (n>>i)&1;
       
       if(root->next[bit]){
           root = root->next[bit];
       }else{
           root = root->next[!bit];
           ans|=(1<<i);
       }
       
   }
   return ans;
}

 


class Solution{   
public:
   int minxorpair(int N, int arr[]){    
       //code here
       
       Trie* root = new Trie();
       insert(root,arr[0]);
       
       int ans = INT_MAX;
       
       for(int i=1;i<N;i++){
           int res = get(root,arr[i]);
           ans = min(ans,res);
           insert(root,arr[i]);
       }
       
       
       return ans;
       
   }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        list<int> l;
        for(int i = 0; i < n; i++) {
            l.push_back(i+1);
        }
        
        while(l.size() > 1) {
            int t = k;
            while(l.size() > 1 and t > 0) {
                l.pop_front();
                t--;
            }
            t = k;
            while(l.size() > 1 and t > 0) {
                l.pop_back();
                t--;
            }
        }
        
        return l.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
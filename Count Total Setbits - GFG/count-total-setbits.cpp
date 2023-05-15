//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int largetPowerofN(long long N) {
        int x = 0;
        while((1<<x) <= N) {
            x++;
        }
        return x - 1;
    }
    
    long long countBits(long long N) {
        if(N == 0) return 0;
        int x = largetPowerofN(N);
        return x*(1<<(x-1)) + (N - (1<<x) + 1) + countBits(N - (1<<x));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
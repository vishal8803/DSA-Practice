//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

vector<int> calc(vector<int> &v) {
    int n = v.size();
    vector<int> ans(n);
    int mn = v[0];
    ans[0] = 0;
    
    for(int i = 1; i < n; i++) {
        mn = min(mn, v[i]);
        ans[i] = max(ans[i-1], v[i] - mn);
    }
    
    return ans;
}

int maxProfit(vector<int>&price){
    int n = price.size();
    vector<int> v1 = calc(price);
    vector<int> v2(n,0);
    int mx = price[n-1];
    
    for(int i = n - 2; i >= 0; i--) {
        mx = max(mx, price[i]);
        v2[i] = max(v2[i+1], mx - price[i]);
    }
    
    int ans = 0;
    for(int i = 0; i < price.size() - 1; i++) {
        ans = max(ans, v1[i] + v2[i+1]);
    }
    return ans;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
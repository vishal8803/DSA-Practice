//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int calc(vector<int> &v, int target) {
        int st = 0;
        int end = v.size() - 1;
        int res;
        while(st <= end) {
            int mid = (st + end) / 2;
            if(v[mid] >= target) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return res;
    }
    vector<int> optimalArray(int n,vector<int> &a){
        vector<int> temp;
        vector<int> prefix(n,0);
        prefix[0] = a[0];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + a[i];
        }
        
        vector<int> ans(n);
        int sum = a[0];
        
        for(int i = 1; i < n; i++) {
            sum += a[i];
            int r = (i+1);
            
            int t ;
            if(r%2) {
                t = a[r/2];
            } else {
                t = (a[r/2] + a[r/2 - 1] )/2;
            }
            int idx = calc(a, t);
            
            int left = 0, right = prefix[i];
            int total = 0;
            if(idx != 0) {
                left = prefix[idx-1];
                right -= prefix[idx-1];
                total += t*(idx) - left;
            }
            // cout<<left<<" "<<right<<endl;
            total += right - t*(i-idx+1);
            ans[i] = total;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<int,int> mp;
        for(auto interval : intervals) {
            mp[interval[0]]++;
            mp[interval[1]]++;
            mp[interval[1]]--;
            mp[(interval[1]+1)]--;
        }
        
        vector<pair<int,int>> v;
        for(auto it : mp) {
            v.push_back({it.first, it.second});
        }
        
        for(int i = 1; i < v.size(); i++) {
            v[i].second += v[i-1].second;
        }
        int ans = -1;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].second >= k) {
                    ans = max(ans, v[i].first);
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int,int> mp;
        
        for(int i : nums) mp[i%k]++;
        
        for(int i : nums) {
            int r = i%k;
            if(k%2==0 and r == k/2) {
                if(mp[r]&1 != 0) return false;
            } else if (r == 0) {
                if(mp[r]&1 != 0) return false;
            }
            else if(mp[r] != mp[k - r]) return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
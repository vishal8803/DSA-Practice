class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp1(n,0), dp2(n,0);
        map<int,int> mp;
        int sum = 0;
        mp[0] = -1;
        
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(mp.find(sum - target) != mp.end()) {
                mn = min(mn, i - mp[sum - target]);
            }
            dp1[i] = mn;
            mp[sum] = i;
        }
        
        sum = 0;
        mp.clear();
        mn = INT_MAX;
        mp[0] = n;
        for(int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            if(mp.find(sum - target) != mp.end()) {
                mn = min(mn, mp[sum - target] - i);
            }
            dp2[i] = mn;
            mp[sum] = i;
        }
        
        int ans = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     cout<<dp1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++) {
        //     cout<<dp2[i]<<" ";
        // }
        for(int i = 0; i < n - 1; i++) {
            if(dp1[i] != INT_MAX and dp2[i+1] != INT_MAX) {
                ans = min(ans, dp1[i] + dp2[i+1]);
            }
        }
        
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};
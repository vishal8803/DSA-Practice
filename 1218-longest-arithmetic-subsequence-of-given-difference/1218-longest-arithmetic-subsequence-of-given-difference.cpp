class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        
        for(int i : arr) {
            dp[i] = 1 + dp[i - difference];
        }
        
        int ans = 0;
        for(auto it : dp) {
            ans = max(ans, it.second); 
        }
        return ans;
    }
};
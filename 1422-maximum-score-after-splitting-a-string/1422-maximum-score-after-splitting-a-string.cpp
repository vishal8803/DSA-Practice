class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> prefix(n+1, 0), suffix(n+1, 0);
        
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + (s[i] == '0');
        }
        
        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (s[i] == '1');
        }
        
        int ans = 0;
        
        for(int i = 1; i < n - 1; i++) {
            ans = max(ans, prefix[i+1] + suffix[i+1]);
        }
        
        ans = max(ans, prefix[1] + suffix[1]);
        
        return ans;
    }
};
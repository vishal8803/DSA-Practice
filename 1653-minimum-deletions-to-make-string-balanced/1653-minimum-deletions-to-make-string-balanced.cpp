class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        if(n == 1) return 0;
        
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        
        if(s[0]=='b') prefix[0] = 1;
        
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1];
            if(s[i] == 'b') {
                prefix[i] += 1;
            }
        }
        
        if(s[n-1]=='a') suffix[n-1] = 1;
        
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i+1];
            if(s[i] == 'a') {
                suffix[i] += 1;
            }
        }
        
        int mn = INT_MAX;
        
        for(int i = 0; i < n - 1; i++) {
            mn = min(mn, prefix[i] + suffix[i+1]);
        }
        
        mn = min(mn, suffix[0]);
        mn = min(mn, prefix[n-1]);
        
        return mn;
    }
};
class Solution {
public:
    vector<int> calc(string s) {
        int n = s.size();
        vector<int> v(n,0);
        
        if(s[0] == '1') v[0] = 1;
        
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') v[i] = v[i-1];
            else {
                v[i] = min(i+1, v[i-1] + 2);
            }
        }
        
        return v;
    }
    
    int minimumTime(string s) {
        int n = s.size();
        if(n == 1) {
            if(s[0] == '0') return 0;
            return 1;
        }
        
        vector<int> prefix = calc(s);
        reverse(s.begin(), s.end());
        vector<int> suffix = calc(s);
        reverse(suffix.begin(), suffix.end());
        int mn = INT_MAX;
        
        for(int i = 0; i < n - 1; i++) {
            mn = min(mn, prefix[i] + suffix[i+1]);
        }
        
        mn = min(mn, prefix[n-1]);
        mn = min(mn, suffix[0]);
        
        return mn;
    }
};
class Solution {
public:
    
    int maximumLength(string s) {
        int n = s.size();
        vector<int> v(n);
        v[0] = 1;
        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                v[i] = 1 + v[i-1];
            } else {
                v[i] = 1;
            }
        }
        
        vector<priority_queue<int, vector<int>, greater<int>>> t(26);
        
        for(int i = 0; i < n; i++) {
            t[s[i]-'a'].push(v[i]);
            if(t[s[i]-'a'].size() > 3) {
                t[s[i]-'a'].pop();
            }
        }
        int ans = -1;
        for(int i = 0; i < 26; i++) {
            if(t[i].size() == 3) {
                ans = max(ans, t[i].top());
            }
        }
        return ans;
        
    }
};
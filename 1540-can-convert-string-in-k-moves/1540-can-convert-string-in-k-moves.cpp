class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return false;
        
        map<int,int> mp;
        
        int mx = 0;
        
        for(int i = 0; i < s.length(); i++) {
            int diff = ((int)(t[i] - s[i]) + 26)%26;
            if(diff==0) continue;
            
            if(mp.find(diff) != mp.end()) {
                mp[diff] += 26;
                mx = max(mx, mp[diff]); 
            } else {
                mp[diff] = diff;
                mx = max(mx, mp[diff]);
            }
        }
        
        return mx <= k;
    }
};
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> freq(26,0);
        for(char ch : s) {
            freq[ch-'a']++;
        }
        
        bool valid = true;
        int i = 0;
        int j = 0;
        int mx = 0;
        
        while(j < s.length()) {
            if((freq[s[j]-'a'] > 0 && freq[s[j]-'a'] < k)) {
                string t = s.substr(i,j-i);
                mx = max(mx, longestSubstring(t, k));
                i = j+1;
                valid = false;
            }
            j++;
        }
        
        if(valid) return s.length();
        else {
            return max(mx, longestSubstring(s.substr(i, j-i), k));
        }
    }
};
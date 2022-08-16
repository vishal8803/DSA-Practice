class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        
        for(char ch : s) {
            freq[ch-'a']++;
        }
        
        int idx = -1;
        
        for(int i = 0; i < s.length(); i++) {
            if(freq[s[i]-'a'] == 1) {
                idx = i;
                break;
            }
        }
        
        return idx;
    }
};
class Solution {
public:
    int calculateBeauty(string &s, vector<int> &freq) {
        // (26,0);
        
        
        int mx = 0;
        int mn = 505;
        
        for(int i : freq) {
            mx = max(mx, i);
            if(i != 0) mn = min(mn, i);
        }
        
        return mx - mn;
    }
    
    int beautySum(string s) {
        int sum = 0;
        
        for(int i = 0; i < s.size(); i++) {
            string temp = "";
            vector<int> freq(26,0);
            for(int j = i; j < s.size(); j++) {
                temp += s[j];
                freq[s[j]-'a']++;
                sum += calculateBeauty(temp, freq);
            }
        }
        
        return sum;
    }
};
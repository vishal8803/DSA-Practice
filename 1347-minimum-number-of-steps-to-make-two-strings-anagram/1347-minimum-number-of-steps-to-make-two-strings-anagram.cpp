class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        vector<int> f1(26,0);
        
        for(char ch : s) {
            f1[ch-'a']++;
        }
        
        for(char ch : t) {
            if(f1[ch-'a']>0) {
                f1[ch-'a']--;
            } else {
                count++;
            }
        }
        
        return count;
    }
};
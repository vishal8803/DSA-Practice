class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f1(26,0), f2(26,0);
        
        for(char ch : s) f1[ch-'a']++;
        for(char ch : t) f2[ch-'a']++;
        
        return f1==f2;
    }
};
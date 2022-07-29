class Solution {
public:
    bool isMatching(string word, string pattern) {
        map<char,char> mp1;
        map<char,char> mp2;
        
        for(int i = 0; i < word.size(); i++){
            char ch1 = word[i];
            char ch2 = pattern[i];
            
            if(mp1.find(ch1) == mp1.end()) mp1[ch1] = ch2;
            if(mp2.find(ch2) == mp2.end()) mp2[ch2] = ch1;
            
            if(mp1[ch1] != ch2 || mp2[ch2] != ch1) return false;
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(string word : words) {
            if(isMatching(word, pattern)) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
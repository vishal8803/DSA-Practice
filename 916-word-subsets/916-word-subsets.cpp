class Solution {
public:
    bool isSubset(vector<int> &f1, vector<int> &f2) {
        for(int i = 0; i < 26; i++) {
            if(f2[i] > f1[i]) return false;
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> freq(26,0);
        
        for(string word : words2) {
            vector<int> t(26,0);
            
            for(char ch : word) {
                t[ch-'a']++;
                freq[ch-'a'] = max(freq[ch-'a'], t[ch-'a']);
            }
        }
        
        for(string word : words1) {
            vector<int> t(26,0);
            for(char ch : word) {
                t[ch-'a']++;
            }
            if(isSubset(t,freq)) ans.push_back(word);
        }
        return ans;
    }
};
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) {
            return false;
        }
        
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        
        for(char ch : word1) {
            f1[ch-'a']++;
        }
        
        for(char ch : word2) {
            f2[ch-'a']++;
        }
        
        for(char ch : word1) {
            if(f2[ch-'a']==0) return false;
        }
        
        for(char ch : word2) {
            if(f1[ch-'a']==0) return false;
        }
        
        if(f1==f2) return true;
        
        for(int i = 0; i < 26; i++) {
            if(f1[i]==0 && f2[i]==0) continue;
            if(f1[i]==f2[i]) continue;
            int target = f2[i];
            bool flag = false;
            for(int j = i + 1; j < 26; j++) {
                if(f1[j]==target) {
                    flag = true;
                    swap(f1[i],f1[j]);
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
        
        return true;
    }
};
class Solution {
public:
    vector<string> getWords(string s) {
        vector<string> v;
        int i = 0;
        
        while(i < s.size()) {
            string temp = "";
            while(i < s.size() and s[i] != ' '){
                temp += s[i++];
            }
            i++;
            v.push_back(temp);
        }
        
        return v;
    }
    
    bool areSentencesSimilar(string s1, string s2) {
        
        vector<string> v1 = getWords(s1);
        vector<string> v2 = getWords(s2);
        
        int i = 0;
        int j = 0;
        int k = v1.size() - 1;
        int l = v2.size() - 1;
        
        while( i <= k and j <= l) {
            if(v1[i] == v2[j]) {
                i++;
                j++;
            } else if(v1[k] == v2[l]) {
                k--;
                l--;
            } else return false;
        }
        
        return true;
    }
};
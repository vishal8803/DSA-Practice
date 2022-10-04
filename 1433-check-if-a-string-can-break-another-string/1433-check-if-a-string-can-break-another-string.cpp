class Solution {
public:
    bool canFind(vector<int> &freq, int i) {
        for(int j = i; j < 26; j++) {
            if(freq[j] > 0) {
                freq[j]--;
                return true;
            }
        }
        return false;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> freq(26,0);
        
        for(char ch : s2) freq[ch - 'a']++;
        
        bool flag = true;
        for(char ch : s1) {
            if(!canFind(freq, ch-'a')) {
                flag = false;
                break;
            } 
        }
        if(flag) return true;
        vector<int> freq2(26,0);
        for(char ch : s1) freq2[ch - 'a']++;
        
        flag = true;
        for(char ch : s2) {
            if(!canFind(freq2, ch-'a')) {
                flag = false;
                break;
            } 
        }
        return flag;
    }
};
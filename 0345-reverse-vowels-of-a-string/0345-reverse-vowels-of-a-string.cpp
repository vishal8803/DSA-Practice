class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) return true;
        
        return false;
    }
    
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i <= j) {
            while(i <= j and !isVowel(s[i])) i++;
            while(i <= j and !isVowel(s[j])) j--;
        
            if(i <= j) {
                swap(s[i++],s[j--]);
            }
        }
        
        return s;
    }
};
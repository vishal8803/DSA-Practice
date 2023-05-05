class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') return true;
        
        return false;
    }
    
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int len = 0;
        int count = 0;
        int ans = 0;
        
        while(j < s.size()) {
            if(isVowel(s[j])) {
                count++;
            }
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k) {
                ans = max(ans, count);
                
                if(isVowel(s[i])) {
                    count--;
                }
                i++;
                j++;
            }
        }
        
        return ans;
        
        
    }
};
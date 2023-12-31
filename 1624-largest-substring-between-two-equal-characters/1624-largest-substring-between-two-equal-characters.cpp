class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = -1;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            int j = s.size() - 1;
            while(j > i and s[j] != ch) {
                j--;
            }
            len = max(len, j - i - 1);
        }
        
        return len;
    }
};
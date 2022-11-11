class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int mx = 0;
        
        int i = 0;
        
        while(i < word.size()) {
            int len = 0;
            unordered_set<char> st;
            while(i < word.size() - 1 and word[i] <= word[i+1]) {
                st.insert(word[i++]);
                len++;
            }
            st.insert(word[i++]);
            len++;
            
            if(st.size() == 5) mx = max(mx, len);
        }
        
        return mx;
    }
};
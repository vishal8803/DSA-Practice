class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        set<char> st;
        
        int i = 0;
        for(char ch : s) {
            if(st.find(ch) == st.end()) {
                st.insert(ch);
            } else {
                st.clear();
                st.insert(ch);
                count++;
            }
        }
        return count + 1;
    }
};
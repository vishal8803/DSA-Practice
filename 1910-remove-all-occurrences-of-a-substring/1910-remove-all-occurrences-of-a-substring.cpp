class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            st.push(s[i]);
            if(st.size() < part.size()) {
                
            } else {
                string t = "";
                while(t.size() != part.size()) {
                    t += st.top();
                    st.pop();
                }
                reverse(t.begin(), t.end());
                if(t==part) {
                    continue;
                } else {
                    for(char ch : t) {
                        st.push(ch);
                    }
                }
            }
        }
        string ans = "";
        while(st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
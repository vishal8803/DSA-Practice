class Solution {
public:
    bool isEquals(char c1, char c2) {
        c1 = tolower(c1);
        c2 = tolower(c2);
        
        return c1 == c2;
    }
    
    string makeGood(string s) {
        stack<char> st;
        
        for(char ch : s) {
            if(st.size() == 0) {
                st.push(ch);
            } else if(islower(ch) and isupper(st.top()) and isEquals(ch, st.top())) {
                st.pop();
            } else if(isupper(ch) and islower(st.top()) and isEquals(ch, st.top())) {
                st.pop();
            } else st.push(ch);
        }
        
        string ans = "";
        while(st.size() > 0 ) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
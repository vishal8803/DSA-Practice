class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        
        for(char ch : s) 
            if(ch != '*') st.push(ch);
            else st.pop();
        
        string ans = "";
        
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};
class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ',') continue;
            if(s[i] != ')') {
                st.push(s[i]);
            } else {
                vector<char> v;
                while(st.size() > 0 and st.top() != '(') {
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char ch = st.top();
                st.pop();
                if(ch == '|') {
                    bool t = false;
                    for(char ch : v) {
                        if(ch == 't') {
                            t = true;
                            break;
                        }
                    }
                    if(t) {
                        st.push('t');
                    } else {
                        st.push('f');
                    }
                } 
                else if(ch == '&') {
                    bool f = false;
                    for(char ch : v) {
                        if(ch == 'f') {
                            f = true;
                            break;
                        }
                    }
                    if(f) {
                        st.push('f');
                    } else {
                        st.push('t');
                    }
                } 
                else if(ch == '!') {
                    if(v[0] == 't') {
                        st.push('f');
                    } else {
                        st.push('t');
                    }
                }
            }
        }
        
        char ch = st.top();
        if(ch == 't') return true;
        return false;
    }
};
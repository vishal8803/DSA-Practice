class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s) {
            if(ch=='a' || ch=='b'){
                st.push(ch);
            }else {
                
                    if(st.size() >= 2) {
                        char ch1 = st.top();
                        st.pop();
                        char ch2 = st.top();
                        st.pop();
                        if(ch1=='b' && ch2=='a'){
                        }else {
                            st.push(ch2);
                            st.push(ch1);
                            st.push(ch);
                            
                        }
                    }else{
                        st.push(ch);
                    }
                }
            
        }
        return st.size()==0;
    }
};
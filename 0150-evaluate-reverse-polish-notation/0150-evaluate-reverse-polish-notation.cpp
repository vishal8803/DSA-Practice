class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(int i=0; i<tokens.size(); i++)
        {
            string s = tokens[i];
            if(s=="+" || s=="/" || s=="*" || s=="-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(s=="+"){
                    st.push((long long)num1+num2);
                }else if(s=="-"){
                    st.push((long long)num2-num1);
                }else if(s=="/"){
                    st.push((long long)num2/num1);
                }else{
                    st.push((long long)num1*num2);
                }
            }else{
                int num = stoi(s);
                st.push(num);
            }
        }
        return st.top();
    }
};
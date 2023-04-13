class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        stack<int> st;
        for(int elem : pushed) {
            if(st.size() == 0) {
                st.push(elem);
            } else {
                while(i < popped.size() and st.size() > 0 and st.top() == popped[i]) {
                    st.pop();
                    i++;
                }
                st.push(elem);
            }
        }
        while(i < popped.size() and st.size() > 0 and st.top() == popped[i]) {
            st.pop();
            i++;
        }
        return st.size() == 0;
    }
};
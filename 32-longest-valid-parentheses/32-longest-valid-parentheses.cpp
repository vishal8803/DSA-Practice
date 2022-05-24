class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0)
            return 0 ;
        stack<int> st ;
        st.push(-1) ;
        int mx = 0 ;
        for(int i =0 ; i<s.length() ; i++)
        {
            if(s[i]=='(')
            {
                st.push(i) ;
            }else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i) ;
                }
               else
                   mx = max(mx,i-st.top()) ;
            }
        }
        return mx ;
    }
};
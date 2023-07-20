class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        for(int i : nums) {
            if(st.size() == 0) st.push(i);
            else {
                int num = st.top();
                int gcd = __gcd(num, i);
                if(gcd > 1) {
                    st.pop();
                    st.push(((long long)num*(long long)i)/gcd);
                    while(st.size() >= 2) {
                        int num1 = st.top();
                        st.pop();
                        int num2 = st.top();
                        st.pop();
                        if(__gcd(num1, num2) > 1) {
                            st.push((num1*num2)/__gcd(num1, num2));
                        } else {
                            st.push(num2);
                            st.push(num1);
                            break;
                        }
                    }
                } else {
                    st.push(i);
                }
                
            }
        }
        vector<int> ans;
        while(st.size() > 0) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
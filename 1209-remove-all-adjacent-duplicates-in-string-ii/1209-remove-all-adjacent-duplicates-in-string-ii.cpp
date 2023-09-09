class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.length(); i++){
            if(st.empty()){
                st.push({s[i],1});
            }else if(s[i]==st.top().first){
                st.push({s[i],st.top().second+1});
                if(st.top().second==k){
                    int t = k;
                    while(t-- && st.size()>0){
                        st.pop();
                    }
                }
            }else{
                st.push({s[i],1});
            }
        }
        string ans = "";
        while(st.size()>0){
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
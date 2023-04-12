class Solution {
public:
    string simplifyPath(string A) {
        stack<string> st;
    
        int i = 0;
        while(i < A.length()) {
            if(A[i]=='/') {
                i++;
                continue;
            }
            string temp = "";
            while(i<A.length() && A[i] != '/'){
                temp += A[i];
                i++;
            }
            if(temp==".") continue;
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }else{
                st.push(temp);
            }
        }
        string ans = "";
        while(st.size() > 0){
            ans ="/" + st.top() + ans;
            st.pop();
        }
        if(ans=="") return "/";
        return ans;
    }
};
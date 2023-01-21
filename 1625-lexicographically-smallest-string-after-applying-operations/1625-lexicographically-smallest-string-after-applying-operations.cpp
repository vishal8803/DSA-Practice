class Solution {
public:
    string rotateString(string s, int b) {
        int n = s.size();
        s = s.substr(n-b) + s.substr(0, n - b);
        return s;
    }
    
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        
        string ans = s;
        
        set<string> st;
        st.insert(s);
        
        while(q.size() > 0) {
            int size = q.size();
            while(size--) {
                string temp = q.front();
                q.pop();
                
                string s1 = rotateString(temp, b); // only rotated
                string s2 = temp; // only added
                
                
                
                for(int i = 1; i < temp.size(); i += 2) {
                    s2[i] = '0' + (((s2[i] - '0') + a)%10);
                }
                
                
                if(st.find(s1) == st.end()) {
                    if(ans > s1) ans = s1;
                    st.insert(s1);
                    q.push(s1);
                }
                
                if(st.find(s2) == st.end()) {
                    if(ans > s2) ans = s2;
                    st.insert(s2);
                    q.push(s2);
                }
            }
        }
        
        return ans;
    }
};
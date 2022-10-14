class Solution {
public:
    int calc(string s, set<string> &st) {
        if(s.size() == 0) return 0;
        
        int count = 0;
        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            temp += s[i];
            if(st.find(temp) == st.end()) {
                st.insert(temp);
                count = max(1 + calc(s.substr(i+1), st), count);
                st.erase(temp);
            }
        }
        return count;
    }
    
    int maxUniqueSplit(string s) {
        set<string> st;
        return calc(s, st);
    }
};
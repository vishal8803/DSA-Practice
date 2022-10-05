class Solution {
public:
    unordered_map<string,int> mp;
    int isValid(string &s) {
        stack<char> st;
        
        for(char ch : s) {
            if(ch>='a' && ch <= 'z') continue;
            if(st.size()==0 || ch=='(') {
                st.push(ch);
            } 
            else if(ch==')') {
                if(st.top()=='(') st.pop();
                else st.push(ch);
            } 
        }
        
        return st.size();
    }
    
    void calc(string &s, int mr, unordered_set<string> &st) {
        if(mp.find(s) != mp.end()) return;
        else mp[s]++;
        if(mr==0) {
            if(isValid(s)==0) st.insert(s);
            return;
        }
        
        for(int i = 0; i < s.size(); i++) {
            string ns = s.substr(0, i) + s.substr(i+1);
            calc(ns, mr - 1, st);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int mr = isValid(s);
        unordered_set<string> ans;
        calc(s, mr, ans);
        
        vector<string> res;
        
        for(auto it : ans) {
            res.push_back(it);
        }
        
        return res;
    }
};
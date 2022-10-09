class Solution {
public:
    char getMinChar(vector<int> &f) {
        for(int i = 0; i < f.size(); i++) {
            if(f[i] != 0) return ('a' + i);
        }
        
        return 'A';
    }
    
    string robotWithString(string s) {
        vector<int> freq(26,0);
        for(char ch : s) freq[ch-'a']++;
        
        string ans = "";
        stack<char> st;
        
        for(char ch : s) {
            st.push(ch);
            freq[ch-'a']--;
            while(st.size() > 0 and st.top() <= getMinChar(freq)) {
                ans += st.top();
                st.pop();
            }
        }
        
        while(st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int i = 0;
        while(i < s.size()) {
            string temp = "";
            while(i < s.size() and s[i] != ' ') {
                temp += s[i++];
            }
            i++;
            if(temp != "") v.push_back(temp);
        }
        
        string ans = "";
        reverse(v.begin(), v.end());
        for(string it : v) ans += it + " ";
        
        return ans.substr(0, ans.size() - 1);
    }
};
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans,v;
        int len = 0;
        int i = 0;
        
        while(i < s.length()) {
            string temp = "";
            while(i < s.length() && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            v.push_back(temp);
            int e = temp.size();
            len = max(len, e);
            i++;
        }
        
        vector<vector<char>> t(len, vector<char>(v.size(),'#'));
        
        for(int j = 0; j < t[0].size(); j++) {
            string s = v[j];
            int k = 0;
            for(int i = 0; i < t.size(); i++) {
                t[i][j] = s[k++];
                if(k==s.length()) break;
            }
        }
        for(int i = 0; i < t.size(); i++) {
            string r = "";
            
            for(int j = 0; j < t[0].size(); j++) {
                if(t[i][j]=='#') r += ' ';
                else r += t[i][j];
            }
            int e = r.size() - 1;
            while(e > 0 && r[e]==' ') {
                e--;
            }
            ans.push_back(r.substr(0,e+1));
        }
        return ans;
        
    }
};
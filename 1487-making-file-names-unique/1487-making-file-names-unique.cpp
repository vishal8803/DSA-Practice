class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        map<string,int> mp;
        
        for(string name : names) {
            if(mp.find(name) == mp.end()) {
                ans.push_back(name);
                mp[name]++;
            }
            else {
                while(true) {
                    string s = name + "(" + to_string(mp[name]) + ")";
                    if(mp.find(s) == mp.end()) break;
                    mp[name]++;
                }
                ans.push_back(name + "(" + to_string(mp[name]) + ")");
                string s = name + "(" + to_string(mp[name]) + ")";
                mp[s]++;
            }
        }
        
        return ans;
    }
};
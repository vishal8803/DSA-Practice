class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> mp;
        for(auto &path : paths) {
            string s1 = path[0];
            string s2 = path[1];
            mp[s1]++;
            int t = mp[s2];
        }
        for(auto it : mp) {
            if(it.second == 0) return it.first;
        }
        return "";
    }
};
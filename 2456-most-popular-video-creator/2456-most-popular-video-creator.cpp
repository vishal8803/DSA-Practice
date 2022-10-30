class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, vector<pair<long long,string>>> mp;
        
        int n = ids.size();
        vector<vector<string>> ans;
        
        for(int i = 0; i < n; i++) {
            mp[creators[i]].push_back({views[i], ids[i]});
        }
        
        vector<pair<long long,string>> v;
        
        for(auto it : mp) {
            string s = it.first;
            vector<pair<long long,string>> t = it.second;
            sort(t.begin(), t.end(), [&](pair<long long,string> &p1, pair<long long,string> &p2) {
                if(p1.first == p2.first) return p1.second < p2.second;
                return p1.first < p2.first;
            });
            mp[s] = t;
            long long sum = 0;
            for(int i = 0; i < t.size(); i++) {
                sum += t[i].first;
            }
            v.push_back({sum, s});
        }
        
        sort(v.begin(), v.end());
        int size = v.size();
        vector<string> temp;
        vector<string> temp2;
        temp.push_back(v[size-1].second);
        for(int i = size - 2; i >= 0; i--) {
            if(v[i].first == v[size-1].first) {
                temp.push_back(v[i].second);
            }
        }
        
        for(string s : temp) {
            vector<pair<long long,string>> e = mp[s];
            long long mx = LONG_MIN;
            for(auto it : e) {
                mx = max(mx, it.first);
            }
            string s2 = "";
            for(auto it : e) {
                if(it.first == mx) {
                    if(s2=="" or s2 > it.second) {
                        s2 = it.second;
                    }
                }
            }
            temp2.push_back(s2);
        }
        
        for(int i = 0; i < temp.size(); i++) {
            ans.push_back({temp[i], temp2[i]});
        }
        return ans;
    }
};
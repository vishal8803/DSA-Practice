class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        
        
        vector<bool> vis(n, false);
        vis[id] = true;
        queue<int> q;
        q.push(id);
        
        int count = 0;
        
        while(q.size() > 0 and level != count ) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();
                
                for(auto it : friends[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
            count++;
        }
        
        map<string, int> mp;
        while(q.size() > 0) {
            int node = q.front();
            q.pop();
            for(auto it : watchedVideos[node]) {
                mp[it]++;
            }
        }
        
        vector<pair<int,string>> ans;
        for(auto it : mp) ans.push_back({it.second, it.first});
        
        sort(ans.begin(), ans.end(), [&](pair<int,string> &p1, pair<int,string> &p2) {
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        });
        
        vector<string> res;
        for(auto it : ans) res.push_back(it.second);
        
        return res;
    }
};
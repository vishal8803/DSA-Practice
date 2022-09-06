class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>> ans;
        
        for(int i = 0; i < r.size(); i++) {
            if(veganFriendly==0) {
                if(r[i][3] <= maxPrice && r[i][4] <= maxDistance) {
                    ans.push_back({r[i][0],r[i][1]});
                }
            } else if(r[i][2]==veganFriendly) {
                if(r[i][3] <= maxPrice && r[i][4] <= maxDistance) {
                    ans.push_back({r[i][0],r[i][1]});
                }
            }
        }
        sort(ans.begin(), ans.end(), [&](pair<int,int> p1, pair<int,int> p2) {
            if(p1.second==p2.second) return p1.first > p2.first;
            return p1.second > p2.second;
        });
        
        vector<int> res;
        for(int i = 0; i < ans.size(); i++) {
            res.push_back(ans[i].first);
        }
        return res;
    }
};
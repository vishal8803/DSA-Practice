class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        int n = plantTime.size();
        
        for(int i = 0; i < n; i++) {
            v.push_back({plantTime[i], growTime[i]});
        }
        
        sort(v.begin(), v.end(), [&](pair<int,int> &p1, pair<int,int> &p2) {
            return p1.second > p2.second;
        });
        
        int start = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            start = start + v[i].first;
            ans = max(ans, start + v[i].second);
        }
        
        return ans;
    }
};
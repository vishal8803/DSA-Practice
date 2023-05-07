class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        vector<int> ans = {1};
        vector<int> v = {o[0]};
        
        for(int i = 1; i < o.size(); i++) {
            if(o[i] >= v[v.size()-1]) {
                v.push_back(o[i]);
                ans.push_back(v.size());
            } else {
                int idx = upper_bound(v.begin(), v.end(), o[i]) - v.begin();
                v[idx] = o[i];
                ans.push_back(idx+1);
            }
            
        }
        
        return ans;
    }
};
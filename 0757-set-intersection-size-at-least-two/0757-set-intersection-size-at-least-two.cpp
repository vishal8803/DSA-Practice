class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [&](vector<int> &v1, vector<int> &v2) {
            if(v1[1] == v2[1]) return v1[0] < v2[0];
            
            return v1[1] < v2[1];
        });
        
        vector<int> res = {v[0][1] - 1, v[0][1]};
        
        for(int i = 1; i < v.size(); i++) {
            int st = v[i][0];
            int end = v[i][1];
            
            if(res.back() < st) {
                res.push_back(end - 1);
                res.push_back(end);
            } else if(res.back() == st) {
                res.push_back(end);
            } else if(res[res.size() - 2] < st) {
                res.push_back(end);
            }
        }
        
        return res.size();
    }
};
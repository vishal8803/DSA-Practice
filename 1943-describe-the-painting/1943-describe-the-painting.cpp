class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<long long> v(100001, 0);
        vector<bool> end(100001, false);
        
        for(auto segment : segments) {
            v[segment[0]] += segment[2];
            v[segment[1]] -= segment[2];
            end[segment[0]] = true;
            end[segment[1]] = true;
        }
        
        for(int i = 1; i < v.size(); i++) {
            v[i] += v[i-1];
        }
        
        vector<vector<long long>> ans;
        int i = 0;
        
        while(i < v.size()) {
            if(v[i] == 0 || end[i] == false) {
                i++;
                continue;
            }
            
            long long t = v[i];
            int j = i;
            i++;
            while(i < v.size() and v[i] == t and end[i] == false) {
                i++;
            }
            
            ans.push_back({j, i, t});
            // i++;
        }
        
        // for(int i = 0; i < 8; i++) {
        //     cout<<v[i]<<" ";
        // }
        
        return ans;
    }
};
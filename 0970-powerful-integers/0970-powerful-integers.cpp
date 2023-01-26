class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        vector<int> v1, v2;
        v1.push_back(1);
        v2.push_back(1);
        
        int t1 = x;
        int t2 = y;
        
        while(t1 < bound and t1 != 1) {
            v1.push_back(t1);
            t1 *= x;
        }
        
        while(t2 < bound and t2 != 1) {
            v2.push_back(t2);
            t2 *= y;
        }
        
        unordered_set<int> ans;
        for(int i : v1) {
            for(int j : v2) {
                if(i + j > bound) break;
                ans.insert(i+j);
            }
        }
        vector<int> v;
        for(auto i : ans){
            v.push_back(i);
        }
        return v;
    }
};
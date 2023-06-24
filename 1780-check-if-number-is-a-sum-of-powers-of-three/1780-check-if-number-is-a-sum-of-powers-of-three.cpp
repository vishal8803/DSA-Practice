class Solution {
public:
    map<pair<int,int>, int> mp;
    
    bool calc(vector<int> &v, int i, int sum) {
        if(sum == 0) return true;
        if(i == v.size() or sum < 0) return false;
        if(mp.find({i, sum}) != mp.end()) return mp[{i,sum}];
        return mp[{i, sum}] = calc(v, i + 1, sum) or calc(v, i + 1, sum - v[i]);
    }
    
    bool checkPowersOfThree(int n) {
        vector<int> v;
        for(int i = 0; i < 17; i++) {
            v.push_back(pow(3, i));
        }
        return calc(v, 0, n);
    }
};
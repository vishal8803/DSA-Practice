class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(k==1) return true;
        map<int,int> mp;
        for(int i : nums) {
            mp[i]++;
        }
        
        while(mp.size() > 0) {
            int elem = mp.begin()->first;
            int t = k;
            while(t--) {
                if(mp.find(elem) == mp.end()) return false;
                mp[elem]--;
                if(mp[elem]==0) mp.erase(elem);
                elem++;
            }
        }
        
        return true;
    }
};
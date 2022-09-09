class Solution {
public:
//     void erase(map<int,int> &mp, int val) {
//         mp[val]--;
//         if(mp[val]==0) mp.erase(val);
//     }
    
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> mp;
        for(int i : changed) mp[i]++;
        
        vector<int> ans;
        
        while(mp.size() > 0) {
            int t = mp.begin()->first;
            if(t==0) {
                if(mp[t]%2) return {};
                int f = mp[t]/2;
                while(f--) ans.push_back(0);
                mp.erase(0);
                continue;
            }
            if(mp.find(2*t) == mp.end()) return {};
            mp[2*t]--;
            mp[t]--;
            
            if(mp[2*t]==0) mp.erase(2*t);
            if(mp[t]==0) mp.erase(t);
            
            ans.push_back(t);
        }
        
        return ans;
    }
};
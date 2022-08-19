class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mp;
        map<int,int> hm;
        
        for(int i : nums) {
            mp[i]++;
        }
        
        for(int i : nums) {
            if(mp[i]==0) continue;
            if(hm[i] > 0) {
                hm[i]--;
                mp[i]--;
                hm[i+1]++;
            }
            else if(mp[i+1] > 0 && mp[i+2] > 0) {
                mp[i]--;
                mp[i+1]--;
                mp[i+2]--;
                hm[i+3]++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
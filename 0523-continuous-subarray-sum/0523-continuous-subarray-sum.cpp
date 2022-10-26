class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum = 0;
        mp[0]= -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(mp.find(sum%k) != mp.end() and i - mp[sum%k] >= 2) return true;
            else if(mp.find(sum%k) == mp.end()) {
                mp[sum%k] = i;
            }
        }
        
        return false;
    }
};
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int count = 0;
        int s = 0;
        mp[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i];
            count += mp[s-goal];
            mp[s]++;
        }
        
        return count;
    }
};
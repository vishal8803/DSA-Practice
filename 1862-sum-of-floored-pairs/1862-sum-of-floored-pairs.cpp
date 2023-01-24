class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<int> mp(100000 + 1, 0);
        sort(nums.begin(), nums.end());
        
        for(auto &i : nums) {mp[i]++;}
        
        long long count = 0;
        int MOD = 1e9 + 7;
        
        for(int i = 1; i < mp.size(); i++) {
            int elem = i;
            int freq = mp[i];
            if(freq == 0) continue;
            int temp = elem;
            
            while(true) {
                int idx1 = lower_bound(nums.begin(), nums.end(), temp) - nums.begin();
                if(idx1 == nums.size()) break;
                int idx2 = lower_bound(nums.begin(), nums.end(), elem*(temp/elem + 1)) - nums.begin();
                
                int rem = idx2 - idx1;
                if(rem == 0) {
                    temp += elem;
                    continue;
                }
                
                long long val = ((rem%MOD)*(temp/elem)%MOD)%MOD;
                long long extra = (val%MOD*freq%MOD)%MOD;
                count = (count%MOD + extra%MOD)%MOD;
                temp += elem;
                if(temp > nums[nums.size() - 1]) break;
            }
        }
        
        return count;
    }
};
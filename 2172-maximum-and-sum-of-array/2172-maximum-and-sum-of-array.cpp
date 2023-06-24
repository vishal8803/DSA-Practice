class Solution {
public:
    map<pair<int,string>, int> mp;
    
    int calc(vector<int> &nums, int i, string &v) {
        if(i == nums.size()) 
        {
            return 0;
        }
        if(mp.find({i, v}) != mp.end()) return mp[{i,v}];
        int sum = 0;
        for(int j = 0; j < v.size(); j++) {
            if(v[j] == 0) {
                v[j] = 1;
                sum = max(sum, (nums[i]&(j+1)) + calc(nums, i + 1, v));
                v[j] = 0;
            }else if (v[j] == 1) {
                v[j] = 2;
                sum = max(sum, (nums[i]&(j+1)) + calc(nums, i + 1, v));
                v[j] = 1;
            }
        }
        
        return mp[{i,v}] = sum;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        
        string v(numSlots, 0);
        return calc(nums, 0, v);
    }
};
class Solution {
public:
    int reverseNumber(int num) {
        int ans = 0;
        while(num > 0) {
            ans = ans*10 + num%10;
            num /= 10;
        }
        
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> rev;
        for(int i : nums) {
            rev.push_back(reverseNumber(i));
        }
        
        map<int,int> mp;
        long long count = 0;
        int MOD = 1e9 + 7;
        
        for(int i = 0; i < nums.size(); i++) {
            int val = nums[i] - rev[i];
            count += mp[val];
            mp[val]++;
            count %= MOD;
        }
        
        return count;
    }
};
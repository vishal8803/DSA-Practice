class Solution {
public:
    bool isPerfectSquare(int num) {
        int t = sqrt(num);
        return t*t == num;
    }
    
    map<pair<int,int>, int> mp;
    
    long long calc(vector<int> &nums, int n, int mask, int prev) {
        if(mask == (1<<n) - 1) return 1;
        
        if(mp.find({mask, prev}) != mp.end()) return mp[{mask, prev}];
        
        long long count = 0;
        if(prev == -1) {
            for(int i = 0; i < n; i++) {
                count += calc(nums, n, (mask | (1<<i)), nums[i]);
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(((mask>>i)&1) == 0 and isPerfectSquare(nums[i] + prev)) {
                    count += calc(nums, n, (mask | (1<<i)), nums[i]);
                }
            }
        }
        
        return mp[{mask, prev}] = count;
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        vector<long long> fact(n+1 ,0);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i <= n; i++) {
            fact[i] = (long long)i*fact[i-1];
        }
        map<int,int> mp;
        for(auto it : nums) {
            mp[it]++;
        }
            
        long long res = calc(nums, nums.size(), 0, -1);
        
        for(auto it : mp) {
            res /= fact[it.second];
        }
        
        return res;
    }
};
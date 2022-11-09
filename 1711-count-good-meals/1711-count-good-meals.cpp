class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> value;
        
        for(int i = 0; i <= 21; i++) {
            value.push_back((1<<i));
        }
        
        int count = 0;
        int MOD = 1e9 + 7;
        
        unordered_map<int,int> mp;
        
        for(int val : deliciousness) {
            for(int p : value) {
                count += mp[p - val];
                
                count %= MOD;
            }
            mp[val]++;
        }
        
        return count;
    }
};
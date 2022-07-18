class Solution {
public:
    int subarraySum(vector<int>& v, int target) {
        map<int,int> mp;
        mp[0] = 1;
        
        int s = 0;
        int count = 0;
        for(int i : v){
            s += i;
            count += mp[s-target];
            mp[s]++;
        }
        
        return count;
    }
};
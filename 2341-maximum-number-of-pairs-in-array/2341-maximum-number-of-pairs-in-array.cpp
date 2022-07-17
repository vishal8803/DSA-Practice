class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        
        for(int i : nums){
            mp[i]++;
        }
        
        int count1 = 0;
        int count2 = 0;
        
        for(auto it : mp){
            int f = it.second;
            count1 += f/2;
            count2 += f%2;
        }
        
        return {count1,count2};
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum = 0;
        int count = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            
            int r = (sum%k);
            if(r<0){
                r+=k;
            }
            
            count+=mp[r];
            mp[r]++;
        }
        return count;
    }
};
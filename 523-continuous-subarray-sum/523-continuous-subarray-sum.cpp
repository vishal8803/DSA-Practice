class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int s = 0;
        mp[0] = -1;
        
        for(int i = 0; i < nums.size(); i++){
            s += nums[i];
            int r = s%k;
            
            if(mp.find(r) == mp.end()){
                mp[r] = i;
            }else{
                int count = i - mp[r];
                if(count>=2){
                    return true;
                }
            }
        }
        return false;
    }
};
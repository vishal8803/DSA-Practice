class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mp;
        
        int mx = 0;
        
        int i = 0;
        int j = 0;
        
        int currentSum = 0;
        
        while(j < nums.size()){
            mp[nums[j]]++;
            currentSum += nums[j];
            
            if(mp.size()==j-i+1){
                mx = max(mx,currentSum);
                j++;
            }else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    currentSum -= nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                    
                    i++;
                }
                
                if(mp.size()==j-i+1){
                    mx = max(mx,currentSum);
                }
                j++;
            }
        }
        return mx;
    }
};
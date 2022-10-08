class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX,diff=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int t = target-nums[i];
            int j=i+1,k=nums.size()-1;
            
            while(j<k){
                int s=nums[j]+nums[k];
                
                if(abs(target-(s+nums[i]))<diff){
                    ans = s+nums[i];
                    diff=abs(target-(s+nums[i]));
                }
                
                if(s==t)
                {
                    return target;
                }else if(s>t){
                    k--;
                }else{
                    j++;
                }
            }
        }
       return ans;
    }
};
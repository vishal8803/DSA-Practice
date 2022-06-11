class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = 0;
        
        for(int i : nums)
            sum += i;
        
        if(sum==x)
            return nums.size();
        
        long long target = sum - x;
        
        if(target < 0)
            return -1;
        
        int i = 0;
        int j = 0; 
        
        int mx = 0;
        long long currentSum = 0;
        
        while(j<nums.size()){
            currentSum += nums[j];
            
            if(currentSum < target){
                j++;
            }else if(currentSum==target){
                mx = max(mx,j-i+1);
                j++;
            }else if(currentSum > target){
                while(i<=j && currentSum > target){
                    currentSum -= nums[i];
                    i++;
                    if(currentSum==target){
                        mx = max(mx,j-i+1);
                    }
                }
                j++;
            }
        }
        if(mx == 0)
            return -1;
        
        return nums.size() - mx;
    }
};
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        
        long long sum = 0;
        long long f = 0;
        long long ans = INT_MIN;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            f += i*nums[i];
        }
        
        int j = n-1;
        ans = max(ans,f);
        
        for(int i = 1; i < n; i++){
            f = f + sum - (n)*nums[j];
            ans = max(ans, f);
            j--;
        }
        
        return ans;
    }
};
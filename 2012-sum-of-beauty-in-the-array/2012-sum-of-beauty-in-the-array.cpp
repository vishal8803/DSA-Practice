class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i-1], nums[i]);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i+1], nums[i]);
        }
        
        int ans = 0;
        
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] > prefix[i-1] && nums[i] < suffix[i+1]) ans += 2;
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) ans += 1;
        }
        
        return ans;
    }
};
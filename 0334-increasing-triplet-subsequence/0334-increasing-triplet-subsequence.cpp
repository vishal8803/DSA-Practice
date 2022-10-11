class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = min(prefix[i-1], nums[i]);
        }
        
        suffix[n-1] = nums[n-1];
        for(int i = n -2; i >= 0; i--) {
            suffix[i] = max(suffix[i+1], nums[i]);
        }
        
        for(int i = 1; i < n - 1; i++) {
            if(prefix[i] < nums[i] and nums[i] < suffix[i+1]) return true;
        }
        
        return false;
    }
};
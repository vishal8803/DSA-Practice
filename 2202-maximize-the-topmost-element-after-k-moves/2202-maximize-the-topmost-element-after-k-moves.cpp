class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1 && k%2==1) return -1;
        
        int mx = 0;
        int n = nums.size();
        
        for(int i = 0; i < min(n,k-1); i++) {
            mx = max(mx, nums[i]);
        }
        
        if(k < n) mx = max(mx,nums[k]);
        
        return mx;
    }
};
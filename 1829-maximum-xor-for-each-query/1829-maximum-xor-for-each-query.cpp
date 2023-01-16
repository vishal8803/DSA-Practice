class Solution {
public:
    int getMax(int xr, int val, int maximumBit) {
        if(xr == 0) return val - 1;
        int ans = 0;
        for(int i = maximumBit - 1; i >= 0; i--) {
            int bit = ((xr>>i) & 1);
            if(bit == 0) {
                int temp = (ans | (1 << i));
                
                if(temp < val) {
                    ans = temp;
                }
            }
        }
        
        return ans;
    }
    
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int xr = 0;
        for(int i : nums) {
            xr = xr ^ i;
        }
        int val = (1 << maximumBit);
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans.push_back(getMax(xr, val, maximumBit));
            xr = xr ^ nums[i];
        }
        
        return ans;
    }
};
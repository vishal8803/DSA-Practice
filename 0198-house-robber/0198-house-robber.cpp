class Solution {
public:
    int rob(vector<int>& nums) {
        int r = nums[0];
        int nr =0 ;
        for(int i=1; i<nums.size(); i++){
            int nnr = nums[i]+nr;
            int nnnr = max(r,nr);
            r=nnr;
            nr=nnnr;
        }
        return max(r,nr);
    }
};
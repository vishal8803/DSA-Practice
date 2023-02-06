class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0;
        int j = n;
        
        vector<int> ans(2*n);
        int k = 0;
        while(i < n) {
            ans[k++] = nums[i++];
            ans[k++] = nums[j++];
        }
        return ans;
    }
};
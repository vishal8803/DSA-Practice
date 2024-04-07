class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            mx = max(mx, cnt);
        }
        
        cnt = 1;
        for(int i = 1; i< nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            mx = max(mx, cnt);
        }
        
        return mx;
    }
};
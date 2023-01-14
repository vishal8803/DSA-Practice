class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            if(nums[i] <= i) {
                v[0]++;
                v[i-nums[i]+1]--;
                v[i+1]++;
                v[n]--;
            } else {
                v[i+1]++;
                v[n-nums[i] + i + 1]--;
            }
        }
        int res;
        int t = 0;
        int c = -1;
        for(int i = 0; i < n; i++) {
            t += v[i];
            if(t > c) {
                res = i;
                c = t;
            }
        }
        return res;
        
    }
};
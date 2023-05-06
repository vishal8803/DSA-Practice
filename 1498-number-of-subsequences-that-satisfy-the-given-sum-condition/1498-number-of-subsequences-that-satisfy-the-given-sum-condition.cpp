class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int MOD = 1e9 + 7;
        int ans = 0;
        int n = nums.size();
        vector<int> p(n, 1);
        for(int i = 1; i < n; i++) {
            p[i] = (p[i-1]*2)%MOD;
        }
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                ans = (ans%MOD + p[j - i]%MOD)%MOD;
                i++;
            } else {
                j--;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int dp[501][501];
    int calc(vector<int> &nums1, vector<int> &nums2, int i, int j) {
        if(i == nums1.size() or j == nums2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int elem = nums1[i];
        int res = calc(nums1, nums2, i+1, j);
        for(int k = j; k < nums2.size(); k++) {
            if(nums2[k] == elem) {
                res = max(res, 1 + calc(nums1, nums2, i + 1, k + 1));
            }
        }
        return dp[i][j] = res;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return calc(nums1, nums2, 0, 0);
    }
};
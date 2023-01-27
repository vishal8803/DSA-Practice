class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long sum = 0;
        
        vector<int> diff(n, 0);
        
        int MOD = 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum = (sum+diff[i])%MOD;
        }
        
        vector<int> arr(n);
        sort(nums1.begin(), nums1.end());
        for(int i = 0; i < n; i++) {
            int j = lower_bound(nums1.begin(), nums1.end(), nums2[i]) - nums1.begin();
            
            if(j != 0 and j != n) {
                arr[i] = min(abs(nums2[i] - nums1[j]), abs(nums2[i] - nums1[j-1]));
            } else if(j == 0) {
                arr[i] = abs(nums2[i] - nums1[j]);
            } else if(j == n) {
                arr[i] = abs(nums2[i] - nums1[j-1]);
            }
        }
        int save = 0;
        for(int i = 0; i < n; i++) {
            save = max(save, diff[i] - arr[i]);
        }
        
        return (sum - save + MOD)%MOD;
    }
};
class Solution {
public:
    int calc(vector<long long> &prefix, int i, int k, int val) {
        long long sub = 0;
        if(i > 0) sub = prefix[i-1];
        
        if((long long)i*val - sub <= k) return (i+1);
        
        int st = 0;
        int end = i - 1;
        int res = -1;
        
        while(st <= end) {
            int mid = (st + end) / 2;
            
            long long diff = 0;
            if(mid > 0) diff = prefix[mid - 1];
            long long v = prefix[i-1] - diff;
            if((long long)val*(i - mid) - v <= k) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        if(res == -1) return 1;
        
        return i - res + 1;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n,0);
        
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, calc(prefix, i, k, nums[i]));
        }
        
        return mx;
    }
};
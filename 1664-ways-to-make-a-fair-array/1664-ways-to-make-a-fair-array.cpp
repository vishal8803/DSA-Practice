class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        
        vector<pair<int,int>> suffix(n);
        vector<pair<int,int>> prefix(n);
        
        int odd = 0;
        int even = 0;
        
        for(int i = 0; i < n; i++) {
            if(i%2) {
                odd += nums[i];
            } else {
                even += nums[i];
            }
            prefix[i] = {odd, even};
        }
        
        odd = 0;
        even = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            if(i%2) {
                odd += nums[i];
            } else {
                even += nums[i];
            }
            suffix[i] = {odd, even};
        }
        
        int ways = 0;
        
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(suffix[i+1].first == suffix[i+1].second) ways++;
            } else if(i == n - 1) {
                if(prefix[i-1].first == prefix[i-1].second) ways++;
            } else {
                if(prefix[i-1].first + suffix[i+1].second == prefix[i-1].second + suffix[i+1].first) ways++;
            }
        }
        
        return ways;
    }
};
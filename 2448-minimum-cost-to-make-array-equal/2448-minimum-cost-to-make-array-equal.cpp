class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        
        vector<pair<long long, long long>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], cost[i]});
        }
        
        sort(v.begin(), v.end());
        vector<long long> prefix_product(n);
        vector<long long> suffix_product(n);
        
        vector<long long> prefix(n);
        vector<long long> suffix(n);
        
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += v[i].second;
            prefix[i] = sum;
        }
        
        sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += v[i].second;
            suffix[i] = sum;
        }
        
        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += v[i].first * v[i].second;
            prefix_product[i] = sum;
        }
        
        sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += v[i].first * v[i].second;
            suffix_product[i] = sum;
        }
        
        
        long long res = LONG_MAX;
        
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                res = min(res, suffix_product[i] - v[i].first*suffix[i]);
            } else if(i == n - 1) {
                res = min(res, v[i].first*prefix[i] - prefix_product[i]);
            } else {
                res = min(res, suffix_product[i] - prefix_product[i-1] - v[i].first*(suffix[i]-prefix[i-1]));
            }
        }
        
        return res;
    }
};
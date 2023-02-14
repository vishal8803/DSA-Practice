class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>> pq2;
        
        int n = nums.size();
        
        vector<long long> suffix(n, 0);
        long long sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            pq1.push(nums[i]);
            if(pq1.size() == n/3) {
                suffix[i] = sum;
            }
            else if(pq1.size() > n/3) {
                sum -= pq1.top();
                pq1.pop();
                suffix[i] = max(suffix[i+1], sum);
            }
        }
        long long ans = LONG_MAX;
        sum = 0;
        for(int i = 0; i < 2*(n/3); i++) {
            sum += nums[i];
            pq2.push(nums[i]);
            if(pq2.size() == (n / 3)) {
                ans = min(ans, sum - suffix[i+1]);
            } else if(pq2.size() > n/3) {
                sum -= pq2.top();
                pq2.pop();
                ans = min(ans, sum - suffix[i+1]);
            }
        }
        // for(int i : suffix) cout<<i<<" "; 
        
        return ans;
    }
};
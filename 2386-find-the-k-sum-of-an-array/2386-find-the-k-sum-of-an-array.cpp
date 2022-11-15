class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += max(0, nums[i]);
            nums[i] = abs(nums[i]);
        }
        
        sort(nums.begin(), nums.end());
        
        vector<long long> v = {0};
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({nums[0], 0});
        while(v.size() < k) {
            auto it = pq.top();
            pq.pop();
            v.push_back(it.first);
            
            
            if(it.second + 1 < nums.size()) {
                pq.push({it.first + nums[it.second + 1], it.second + 1});
                pq.push({it.first - nums[it.second] + nums[it.second + 1], it.second + 1});
            }
        }
        
        return sum - v[k-1];
    }
};
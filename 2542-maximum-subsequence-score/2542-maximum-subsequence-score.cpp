class Solution {
public:
    long long res(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        int n = nums1.size();
        
        for(int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }
        
        sort(v.rbegin(), v.rend());
        
        
        int i = 0;
        int j = 0;
        long long sum = 0;
        long long ans = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n; i++) {
            pq.push(v[i].second);
            sum += v[i].second;
            
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k) {
                ans = max(ans, sum*(long long)v[i].first);
            }
        }
        
        return ans;
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        return res(nums1, nums2, k);
    }
};
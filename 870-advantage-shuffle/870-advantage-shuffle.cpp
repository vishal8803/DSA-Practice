class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(int i = 0; i < nums2.size(); i++) {
            pq.push({nums2[i],i});
        }
        
        sort(nums1.begin(), nums1.end());
        int i = 0;
        int j = nums1.size() - 1;
        vector<int> ans(nums1.size());
        
        while(i <= j) {
            auto it = pq.top();
            pq.pop();
            
            if(it.first < nums1[j]) {
                ans[it.second] = nums1[j--];
            } else {
                ans[it.second] = nums1[i++];
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int calc(vector<int> &nums1, vector<int> &nums2, int curr1, int curr2, int i, map<pair<int, pair<int,int>>, int> &mp) {
        if(i == nums1.size()) return 0;
        // if(dp[i] != -1) return dp[i];
        
        if(mp.find({i, {curr1, curr2}}) != mp.end()) {
            return mp[{i, {curr1, curr2}}];
        }
        
        if(i == 0) 
        {
            int r1 = calc(nums1, nums2, nums1[0], nums2[0], i + 1, mp);
            
            int r2 = calc(nums1, nums2, nums2[0], nums1[0], i + 1, mp);
            
            
            return mp[{i, {curr1, curr2}}] = min(r1, 1 + r2);
        } 
        else 
        {
            if(nums1[i] <= curr1 or nums2[i] <= curr2) {
                
                if(nums2[i] <= curr1 or nums1[i] <= curr2) {
                    return mp[{i, {curr1, curr2}}] = 1e6;
                }
                
                int r = 1 + calc(nums1, nums2, nums2[i], nums1[i], i + 1, mp);
                
                return mp[{i, {curr1, curr2}}] = r;
            } else {
                
                int r1 = calc(nums1, nums2, nums1[i], nums2[i], i + 1, mp);
                
                if(curr1 < nums2[i] and curr2 < nums1[i]) {
                    r1 = min(r1, 1 + calc(nums1, nums2, nums2[i], nums1[i], i + 1, mp));
                }
                
                return mp[{i, {curr1, curr2}}] = r1;
            }
        }
        return -1;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<pair<int, pair<int,int>>, int> mp;
        return calc(nums1, nums2, -1, -1, 0, mp);
    }
};
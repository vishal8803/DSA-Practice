class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int i = 0;
        int j = 0;
        
        multiset<long long> st;
        while(j < nums.size()) {
            st.insert(nums[j]);
            
            if(st.count(nums[j]) > 1) return true;
            auto it1 = st.lower_bound(nums[j]);
            auto it2 = st.lower_bound(nums[j] + 1);
            
            if(it2 != st.end()) {
                long long diff2 = *it2 - (long long)nums[j];
                if(diff2 <= valueDiff) return true;
            }
            
            if(it1 != st.begin()) {
                it1--;
                long long diff1 = (long long)nums[j] - *it1;
                
                
                if(diff1 <= valueDiff) return true;
            }
            
            if(j - i + 1 <= indexDiff) {
                j++;
            } else {
                st.erase(st.find(nums[i++]));
                j++;
            }
        }
        
        return false;
    }
};
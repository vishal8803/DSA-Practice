class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> st;
        int missing, twice;
        for(int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]) != st.end()) {
                twice = nums[i];
            }
            st.insert(nums[i]);
        }
        
        for(int i = 1; i <= nums.size(); i++) {
            if(st.find(i) == st.end()) {
                missing = i;
            }
        }
        
        return {twice, missing};
        
    }
};
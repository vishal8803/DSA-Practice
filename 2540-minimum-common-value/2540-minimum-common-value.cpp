class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        for(int i : nums1) st.insert(i);
        
        for(int i : nums2) {
            if(st.find(i) != st.end()) return i;
        }
        
        return -1;
    }
};
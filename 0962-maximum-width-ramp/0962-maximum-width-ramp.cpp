class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(st.empty() or nums[st.top()] < nums[i]) st.push(i);
        }
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            while(st.size() > 0 and nums[st.top()] >= nums[i]) {
                ans = max(ans, st.top() - i);
                st.pop();
            }
        }
        
        return ans;
    }
};
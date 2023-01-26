class Solution {
public:
    vector<int> leftSmaller(vector<int> &nums) {
        stack<int> st;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            if(st.size() == 0) {
                ans.push_back(-1);
            } else if(st.size() > 0 and nums[st.top()] < nums[i]) {
                ans.push_back(st.top());
            } else if(st.size() > 0 and nums[st.top()] >= nums[i]) {
                while(st.size() > 0 and nums[st.top()] >= nums[i]) {
                    st.pop();
                }
                if(st.size() == 0) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> rightSmaller(vector<int> &nums) {
        stack<int> st;
        vector<int> ans;
        int n = nums.size();
        
        for(int i = n - 1; i >= 0; i--) {
            if(st.size() == 0) {
                ans.push_back(n);
            } else if(st.size() > 0 and nums[st.top()] < nums[i]) {
                ans.push_back(st.top());
            } else if(st.size() > 0 and nums[st.top()] >= nums[i]) {
                while(st.size() > 0 and nums[st.top()] >= nums[i]) {
                    st.pop();
                }
                if(st.size() == 0) {
                    ans.push_back(n);
                } else {
                    ans.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int> lt = leftSmaller(nums);
        vector<int> rt = rightSmaller(nums);
        
        for(int i = 0; i < nums.size(); i++) {
            int len = rt[i] - lt[i] - 1;
            // cout<<len<<" ";
            if(nums[i] > threshold/len)return len;
        }
        
        return -1;
    }
};
class Solution {
public:
    vector<int> leftSmaller(vector<int> &nums) {
        vector<int> ans;
        stack<int> st;
        
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
        vector<int> ans;
        stack<int> st;
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
    
    int maximumScore(vector<int>& nums, int k) {
        int mx = 0;
        vector<int> lt = leftSmaller(nums);
        vector<int> rt = rightSmaller(nums);
        
        for(int i = 0; i < nums.size(); i++) {
            if(lt[i] < k and rt[i] > k) {
                int val = nums[i]*(rt[i] - lt[i] - 1);
                // cout<<nums[i]<<" "<<lt[i] << " "<<rt[i]<<" "<<val<<endl;
                mx = max(mx, val);
            }
        }
        
        return mx;
    }
};
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> currMin(n,0) ;
        int mn = INT_MAX ;
        for(int i =0 ; i<n ; i++)
        {
            mn=min(mn,nums[i]) ;
            currMin[i] = mn ;
        }
        stack<int> st ;
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && st.top()<=currMin[i])
            {
                st.pop() ;
            }
            if(!st.empty() && st.top()>currMin[i] && nums[i]>st.top())
                return true ;
            st.push(nums[i] );
        }
        return false ;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0;
        int j = 0;
        int mx = 0;
        
        multiset<int> st;
        
        while(j < nums.size()) {
            st.insert(nums[j]);
            int min_element = *st.begin();
            int max_element = *st.rbegin();
            
            if(max_element - min_element <= limit) {
                mx = max(mx, j - i + 1);
                j++;
            } else {
                
                while(i <= j  && *st.rbegin() - *st.begin() > limit) {
                    st.erase(st.find(nums[i]));
                    // cout<<*st.rbegin() << " "<< *st.begin() << endl;
                    i++;
                }
                
                mx = max(mx, j - i + 1);
                j++;
            }
            // cout<<i<<" "<<j<<endl;
        }
        
        return mx;
    }
};
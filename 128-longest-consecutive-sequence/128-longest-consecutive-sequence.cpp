class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i : nums){
            st.insert(i);
        }
        
        int ans = 0;
        for(int i : nums){
            if(!st.count(i-1)){
                int cl = 1;
                int cn = i;
                while(st.count(cn+1)){
                    cl++;
                    cn++;
                }
                ans = max(ans, cl);
            }
        }
        return ans;
    }
};
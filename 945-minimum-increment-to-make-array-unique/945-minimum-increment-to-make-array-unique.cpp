class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<int> st;
        
        for(int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
                temp.push_back(nums[i]);
            } else {
                int num = temp[temp.size()-1];
                st.insert(num+1);
                temp.push_back(num+1);
            }
        }
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            count += temp[i] - nums[i];
        }
        return count;
    }
};
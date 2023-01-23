class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> v;
        
        for(int i = 0; i < nums.size(); i++) {
            while(v.size() > 0 and v.back() > nums[i] and v.size() - 1 + nums.size() - i >= k)
                v.pop_back();
            if(v.size() < k){
                v.push_back(nums[i]);
            }
        }
        
        return v;
    }
};
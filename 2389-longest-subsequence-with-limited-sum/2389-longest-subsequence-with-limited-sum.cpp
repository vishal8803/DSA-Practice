class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for(int q : queries) {
            int sum = 0;
            int size = 0;
            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if(sum > q) {
                    break;
                } else {
                    size = i + 1;
                }
            }
            ans.push_back(size);
        }
        
        return ans;
    }
};
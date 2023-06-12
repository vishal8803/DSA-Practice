class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int j = 0;
        vector<string> ans;
        while(j<nums.size()){
            long long lower = nums[j];
            long long upper = nums[j];
            while(j < nums.size() && nums[j]==upper){
                upper++;
                j++;
            }
            if(lower == upper-1){
                string temp = to_string(lower);
                ans.push_back(temp);
            }else{
                string temp = to_string(lower) + "->" + to_string(upper-1);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
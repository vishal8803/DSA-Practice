class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        
        for(int i : nums) {
            if(i%2==0) sum += i;
        }
        
        vector<int> ans;
        
        for(auto q : queries) {
            int val = q[0];
            int idx = q[1];
            
            if(nums[idx]%2!=0) {
                nums[idx] += val;
                if(nums[idx]%2==0)
                    sum += nums[idx];
            } else {
                int t = nums[idx];
                nums[idx] += val;
                if(nums[idx]%2==0) {
                    sum += val;
                } else {
                    sum -= t;
                }
            }
            ans.push_back(sum);
        }
        
        return ans;
    }
};
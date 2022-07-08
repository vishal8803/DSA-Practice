class Solution {
public:
    vector<int> res;
    
    void calc(vector<int> &nums, int i, int prev, vector<int> curr, vector<int> &mem){
        if(curr.size() > res.size()){
            res = curr;
        }
        
        for(int j = i; j < nums.size(); j++){
            int t = curr.size();
            if(t > mem[j] && nums[j]%prev==0){
                mem[j] = curr.size();
                curr.push_back(nums[j]);
                calc(nums,j+1,nums[j],curr,mem);
                curr.pop_back();
            }
        }
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        res = vector<int>();
        vector<int> dp(nums.size(),-1);
        
        calc(nums,0,1,{},dp);
        return res;
    }
};
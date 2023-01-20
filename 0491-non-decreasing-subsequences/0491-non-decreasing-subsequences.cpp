class Solution {
public:
    void count(vector<int> &nums, int i, int prev, vector<int> temp, set<vector<int>> &ans){
        
        if(i==nums.size()){
            if(temp.size()>=2){
                ans.insert(temp);
            }
            return;
        }
        
        if(nums[i]>=prev){
            temp.push_back(nums[i]);
            count(nums,i+1,nums[i],temp,ans);
            temp.pop_back();
            count(nums,i+1,prev,temp,ans);
        }else{
            count(nums,i+1,prev,temp,ans);
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        
        count(nums,0,-101,{},ans);
        
        vector<vector<int>> temp;
        for(auto it = ans.begin(); it != ans.end(); it++){
            temp.push_back(*it);
        }
        return temp;
    }
};
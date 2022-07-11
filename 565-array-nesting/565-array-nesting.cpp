class Solution {
public:
    void calc(vector<int> &nums, vector<bool> &visited, int idx, int &count){
        if(visited[idx]){
            return;
        }
        count++;
        visited[idx] = true;
        calc(nums,visited,nums[idx],count);
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int count = 0;
                calc(nums,visited,i,count);
                ans = max(ans,count);
            }
        }
        
        return ans;
    }
};
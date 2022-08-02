class Solution {
public:
    int calc(vector<int> nums, int elem) {
        int fi,fj;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]==elem){
                fi = i;
                break;
            }
        }
        
        for(int i = nums.size()-1; i>=0; i--) {
            if(nums[i]==elem){
                fj = i;
                break;
            }
        }
        return fj-fi+1;
    }
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> mp;
        
        for(int i : nums) {
            mp[i]++;
        }
        
        int mx = INT_MIN;
        for(auto it : mp) {
            mx = max(mx, it.second);
        }
        
        vector<int> frequent;
        
        for(auto it : mp) {
            if(it.second==mx) frequent.push_back(it.first);
        }
        
        int ans = INT_MAX;
        for(int i : frequent) {
            ans = min(ans, calc(nums,i));
        }
        
        return ans;
    }
};
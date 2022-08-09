class Solution {
public:
    int find_position(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) return i;
        }
        return -1; // although this condition never arise
    }
    
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        
        int maxPos = find_position(nums, mx);
        int minPos = find_position(nums, mn);
        
        
        int result1 = max(maxPos, minPos) + 1;
        int result2 = max(n-maxPos, n-minPos);
        int result3;
        
        if(maxPos > minPos) {
            result3 = 1 + minPos + n - maxPos;
        } else {
            result3 = 1 + maxPos + n - minPos;
        }
        
        return min(result1, min(result2,result3));
    }
};
class Solution {
public:
    bool isPossible(vector<int> &nums, int maxOperations, int maxSize) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxSize) {
                if(nums[i]%maxSize == 0) {
                    count += nums[i]/maxSize - 1;
                } else {
                    count += nums[i]/maxSize;
                }
            }
        }
        
        return count <= maxOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int res;
        int st = 1;
        int end = 1e9;
        
        while(st <= end) {
            int mid = (st + end)/ 2;
            if(isPossible(nums, maxOperations, mid)) {
                res = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return res;
    }
};
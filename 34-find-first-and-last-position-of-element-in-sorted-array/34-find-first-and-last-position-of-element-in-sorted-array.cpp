class Solution {
public:
    bool isPresent(vector<int> &nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        
        while(st<=end) {
            int mid = (st+end)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid] > target) end = mid - 1;
            else st = mid + 1;
        }
        
        return false;
    }
    
    int firstPosition(vector<int> &nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        int ans;
        
        while(st<=end) {
            int mid = (st+end)/2;
            if(nums[mid] == target){
                ans = mid;
                end = mid - 1;
            }else if(nums[mid] > target) {
                end = mid - 1;
            }else {
                st = mid + 1;
            }
        }
        
        return ans;
    }
    
    int lastPosition(vector<int> &nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        int ans;
        
        while(st<=end) {
            int mid = (st+end)/2;
            if(nums[mid] == target){
                ans = mid;
                st = mid + 1;
            }else if(nums[mid] > target) {
                end = mid - 1;
            }else {
                st = mid + 1;
            }
        }
        
        return ans;
    }
    
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(isPresent(nums,target)==false) return {-1,-1};
        
        int first = firstPosition(nums,target);
        int last = lastPosition(nums,target); 
        
        return {first, last};
    }
};
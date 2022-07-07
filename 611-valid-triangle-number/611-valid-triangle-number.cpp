class Solution {
public:
    int calc(vector<int> &nums, int st, int end, int target){
        
        while(st<=end){
            int mid = (st+end)/2;
            
            if(nums[mid]>=target){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return st;
    }
    
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i]==0 || nums[j]==0){
                    continue;
                }
                int target = nums[i] + nums[j];
                int k = calc(nums,j+1,nums.size()-1,target);
                count += k-j-1;
            }
        }
        
        return count;
    }
};
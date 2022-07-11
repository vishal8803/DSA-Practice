class Solution {
public:
    int calc(vector<int> &nums, int i, int j, int chance){
        if(i>j)
            return 0;
        
        if(chance==0){
            return max(nums[i]+calc(nums,i+1,j,1), nums[j]+calc(nums,i,j-1,1));
        }else{
            return min(calc(nums,i+1,j,0),calc(nums,i,j-1,0));
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        long long two = 0;
        int n = nums.size();
        
        for(int i : nums){
            two += i;
        }
        
        long long one = (long long)calc(nums,0,n-1,0);
        two -= one;
        
        return one>=two;
    }
};
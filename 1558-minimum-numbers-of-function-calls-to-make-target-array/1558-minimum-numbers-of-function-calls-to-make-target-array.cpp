class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        while(true) {
            int zero = 0;
            int i = 0;
            
            for(i = 0; i < n; i++) {
                if(nums[i]&1) break;
                if(nums[i]==0) zero++;
            }
            if(zero == n) return count;
            
            if(i==n) {
                count++;
                for(int i = 0; i < n; i++) {
                    nums[i]/=2;
                }
            }
            
            for(int i = 0; i < n; i++) {
                if(nums[i]&1) {
                    count++;
                    nums[i]--;
                }
            }
        }
        return -1;
    }
};
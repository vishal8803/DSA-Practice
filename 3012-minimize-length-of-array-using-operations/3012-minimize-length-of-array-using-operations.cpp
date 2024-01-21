class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int cnt = 0;
        int num = nums[0];
        int i = 0;
        while(i < nums.size() and num == nums[i]) {
            cnt++;
            i++;
        }
        
        if(cnt == 1) return 1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != num and nums[i]%num != 0) return 1;
        }
        
        if(cnt%2 == 0) return cnt/2;
        return cnt/2 + 1;
    }
};
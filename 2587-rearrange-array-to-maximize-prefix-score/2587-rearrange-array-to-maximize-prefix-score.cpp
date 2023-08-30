class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(begin(nums), end(nums));
        reverse(begin(nums), end(nums));
        long long sum = 0;
        int cnt = 0;
        for(int i : nums) {
            sum += i;
            if(sum > 0) cnt++;
        }
        
        return cnt;
    }
};
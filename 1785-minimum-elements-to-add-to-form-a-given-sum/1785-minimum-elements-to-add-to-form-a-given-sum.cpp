class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(int i : nums) {
            sum += i;
        }
        
        long long diff = abs(sum - (long long)goal);
        
        return diff/limit + (diff%limit>0?1:0);
    }
};
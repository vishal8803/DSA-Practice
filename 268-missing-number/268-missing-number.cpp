class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = 0;
        
        for(int i : nums)
            s += i;
        
        int n = nums.size();
        
        int s2 = ((n)*(n+1))/2;
        
        return abs(s-s2);
        
    }
};
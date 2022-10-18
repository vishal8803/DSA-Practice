class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        
        int i = 0;
        int j = 0;
        
        while(j < nums.size()) {
            sum += nums[j];
            if(sum*(long long)(j-i+1) < k) {
                ans += j-i+1;
                j++;
            } else {
                while(i <= j and sum*(long long)(j-i+1) >= k) {
                    sum -= nums[i];
                    i++;
                }
                if(i <= j and sum*(long long)(j-i+1) < k) {
                    ans += j-i+1;
                }
                j++;
            }
        }
        
        return ans;
    }
};
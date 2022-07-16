class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            prefix[i] = (long long)nums[i] + (long long)prefix[i-1];
        }
        
        int mn = INT_MAX;
        int idx;
        
        for(int i = 0; i < n; i++){
            int avg1 = (prefix[i])/(i+1);
            int avg2;
            if(n-i-1==0)
                avg2 = 0;
            else
                avg2 = (prefix[n-1]-prefix[i])/(n-i-1);
            
            if(abs(avg1-avg2) < mn){
                mn = min(mn, abs(avg1-avg2));
                idx = i;
            }
        }
        
        return idx;
    }
};
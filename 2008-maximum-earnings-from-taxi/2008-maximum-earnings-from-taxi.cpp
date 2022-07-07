class Solution {
public:
    int calc(int st, int end, vector<vector<int>> &rides, int target){
        int ans = rides.size();
        while(st<=end){
            int mid = (st+end)/2;
            if(rides[mid][0]>=target){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size()+1);
        dp[dp.size()-1] = 0;
        
        for(int i = dp.size()-2; i>=0; i--){
            int idx = calc(i+1,dp.size()-2,rides,rides[i][1]);
            dp[i] = max(dp[i+1], dp[idx] + rides[i][1] - rides[i][0] + rides[i][2]);
        }
        
        return dp[0];
    }
};
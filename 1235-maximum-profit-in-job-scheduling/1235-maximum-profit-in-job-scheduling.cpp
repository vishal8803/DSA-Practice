class Solution {
public:
    int calc(int st, int end, vector<vector<int>> &jobs, int target){
        int res = jobs.size();
        
        while(st<=end){
            int mid = (st+end)/2;
            if(jobs[mid][0]>=target){
                res = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        
        return res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n+1);
        
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--){
            int idx = calc(i+1,n-1,jobs,jobs[i][1]);
            dp[i] = max(dp[i+1], jobs[i][2] + dp[idx]);
        }
        
        return dp[0];
    }
};
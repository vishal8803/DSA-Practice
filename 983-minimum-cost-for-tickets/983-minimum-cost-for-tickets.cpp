class Solution {
public:
    int find(vector<int> &days, int target) {
        int st = 0;
        int end = days.size() - 1;
        int rs;
        
        while(st<=end) {
            int mid = (st+end)/2;
            if(days[mid] ==target) {
                return mid + 1;
            } else if(days[mid] > target) {
                rs = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return rs;
    }
    
    int calc(vector<int> &days, vector<int> &costs, int i, vector<int> &dp) {
        if(i>=days.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int r1 = costs[0] + calc(days, costs, find(days,days[i]), dp);
        int r2 = costs[1] + calc(days, costs, find(days,days[i]+6), dp);
        int r3 = costs[2] + calc(days, costs, find(days,days[i]+29), dp);
        
        return dp[i] = min(r1, min(r2,r3));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return calc(days, costs, 0, dp);
    }
};
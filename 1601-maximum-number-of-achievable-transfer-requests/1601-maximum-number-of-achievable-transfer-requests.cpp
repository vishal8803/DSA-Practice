class Solution {
public:
    int dp[65540][21];
    int calc(vector<vector<int>> &requests, int n, int mask, int i) {
        if(i == requests.size()) {
            vector<int> indegree(n), outdegree(n);
            int count = 0;
            for(int j = 0; j < requests.size(); j++) {
                if((mask>>j)&1) {
                    count++;
                    int x = requests[j][0];
                    int y = requests[j][1];
                    indegree[y]++;
                    outdegree[x]++;
                }
            }
            for(int i = 0; i < n; i++) {
                if(indegree[i] != outdegree[i]) return 0;
            }
            return count;
        }
        
        if(dp[mask][i] != -1) return dp[mask][i];
        
        int res = calc(requests, n, mask, i + 1);
        res = max(res, calc(requests, n, mask | (1<<i), i + 1));
        return dp[mask][i] = res;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        memset(dp , -1, sizeof(dp));
        return calc(requests, n, 0, 0);
    }
};
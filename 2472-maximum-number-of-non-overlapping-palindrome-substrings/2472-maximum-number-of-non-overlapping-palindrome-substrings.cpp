class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end());
        if(intervals.size() <= 1) return intervals.size();
        vector<int> temp = intervals[0];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(temp[1] < intervals[i][0]){
                temp = intervals[i];
                continue;
            }
            if(temp[1]<=intervals[i][1]){
                count++;
                continue;
            }else if(temp[1]>intervals[i][1]){
                count++;
                temp = intervals[i];
                continue;
            }
        }
        return intervals.size() - count;
    }
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        vector<vector<int>> v;
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(g == 0) {
                    dp[i][j] = 1;
                } else if(g == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = 1;
                    }
                } else {
                    if(dp[i+1][j-1] and s[i]==s[j]) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] and j-i+1 >= k) {
                    v.push_back({i,j});
                }
            }
        }
        
        return eraseOverlapIntervals(v);
    }
};
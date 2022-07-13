class Solution {
public:
    int calc(vector<vector<int>> &pairs, int target){
        int st = 0;
        int end = pairs.size()-1;
        int ans = end + 1;
        
        while(st<=end){
            int mid = (st+end)/2;
            if(pairs[mid][0]>target){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        
        int dp[n+1];
        dp[n] = 0;
        
        for(int i = n - 1; i >= 0; i--){
            int idx = calc(pairs,pairs[i][1]);
            dp[i] = max(dp[i+1], 1 + dp[idx]);
        }
        
        return dp[0];
    }
};
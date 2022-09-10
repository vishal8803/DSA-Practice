class Solution {
public:
    int MOD = 1000000007;
    int calc(int count, vector<int> &temp, int num) {
        vector<long long> dp(count,0);
        int val = temp[num];
        dp[0] = 1;
        
        for(int i = 1; i < dp.size(); i++) {
            int t = val;
            int j = i - 1;
            if(i-val < 0 ){
                dp[i] = 1;
                while(j>=0) {
                    dp[i] += dp[j--];
                }
            }else{
                while(t-- && j >= 0) {
                    dp[i] += dp[j--];
                }
            }
            dp[i] %= MOD;
        }
        
        return dp[count-1];
    }
    
    int countTexts(string s) {
        vector<int> temp = {0,0,3,3,3,3,3,4,3,4};
        long long ways = 1;
        
        int i = 0;
        
        while(i < s.length()) {
            int count = 0;
            char ch = s[i];
            while(i < s.length() && s[i]==ch) {
                count++;
                i++;
            }
            ways *= calc(count,temp,(ch-'0'));
            ways %= MOD;
        }
        
        return ways;
    }
};
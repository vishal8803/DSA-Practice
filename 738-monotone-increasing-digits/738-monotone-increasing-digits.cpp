class Solution {
public:
    void calc(int n, long long curr, long long &ans) {
        if(curr > n) {
            return;
        }
        ans = max(ans, curr);
        int prev = curr%10;
        
        for(int i = prev; i <= 9; i++) {
            if(curr==0 && i==0) continue;
            calc(n, (long long)curr*10 + i, ans);
        }
    }
    
    int monotoneIncreasingDigits(int n) {
        long long ans = INT_MIN;
        calc(n,0,ans);
        return ans;
    }
};
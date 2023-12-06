class Solution {
public:
    int calcSum(int n) {
        return (n*(n+1))/2;
    }
    
    int totalMoney(int n) {
        int l = floor(n/7.0);
        int h = ceil(n/7.0);
        int ans = 0;
        
        for(int i = 1; i <= l; i++) {
            int temp = calcSum(i + 6) - calcSum(i - 1);
            ans += temp;
        }
        
        if(l != h) {
            ans += calcSum(h + n%7 - 1) - calcSum(h - 1);
        } 
        
        return ans;
    }
};
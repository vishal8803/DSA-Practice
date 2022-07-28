class Solution {
public:
    string baseNeg2(int n) {
        if(n==0) return "0";
        
        string ans = "";
        
        while(n!=0) {
            if(abs(n%2)==1) {
                ans += "1";
                n=(n-1)/-2;
            }else {
                ans += "0";
                n=n/-2;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
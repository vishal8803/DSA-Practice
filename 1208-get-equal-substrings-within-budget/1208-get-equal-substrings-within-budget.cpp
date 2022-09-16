class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j = 0;
        int cost = 0;
        int mxLen = 0;
        
        int n = s.length();
        
        while(j < n) {
            cost += abs(s[j] - t[j]);
            if(cost <= maxCost) {
                mxLen = max(mxLen, j-i+1);
                j++;
            } else {
                while(i <= j && cost > maxCost) {
                    cost -= abs(s[i] - t[i]);
                    i++;
                }
                
                if(cost <= maxCost) {
                    mxLen = max(mxLen, j-i+1);
                }
                j++;
            }
        }
        
        return mxLen;
    }
};
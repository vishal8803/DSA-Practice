class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        int cnt2 = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(i % 2 == 0) {
                if(s[i] != '0') cnt++;
                else cnt2++;
            } else {
                if(s[i] != '1') cnt++;
                else cnt2++;
            }
        }
        
        return min(cnt, cnt2);
    }
};
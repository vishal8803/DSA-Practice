class Solution {
public:
    int minSwaps(string s) {
        int c1 = 0;
        int c2 = 0;
        
        for(char ch : s) {
            if(ch=='0') c1++;
            else c2++;
        }
        
        if(abs(c1-c2) > 1) return -1;
        
        c1 = 0;
        c2 = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(i%2 and s[i] == '0') c1++;
            else if(i%2==0 and s[i] == '1') c1++;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(i%2 and s[i] == '1') c2++;
            else if(i%2==0 and s[i] == '0') c2++;
        }
        if(c1%2==0 and c2%2==0) {
            return min(c1/2, c2/2);
        } else if(c1%2==0) return c1/2;
        else if(c2%2==0) return c2/2;
        
        return -1;
    }
};
class Solution {
public:
    string invert(string s) {
        for(int i = 0; i < s.length(); i++) {
            s[i] = (s[i]=='1'?'0':'1');
        }
        return s;
    }
    
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        
        string s = "0";
        
        while(n > 1) {
            string t = invert(s);
            reverse(t.begin(), t.end());
            s = s + "1" + t;
            n--;
        }
        
        return s[k-1];
    }
};
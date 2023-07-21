class Solution {
public:
    unsigned long long convertoNum(string s) {
        unsigned long long  ans = 0;
        
        for(char ch : s) {
            ans = (unsigned long long )ans*(unsigned long long)(10) + (ch - '0');
        }
        return ans;
    }
    
    int calc(string s, int i, string prev, int count) {
        if(i == s.size()) {
            
            if(count > 1)
                return true;
            
            return false;
        }
        
        string temp = "";
        for(int j = i; j < s.size(); j++) {
            temp = temp + s[j];
            if(prev == ""){
                if(calc(s, j + 1, temp, count + 1)) return true;
            } else {
                
                unsigned long long p = convertoNum(prev);
                unsigned long long c = convertoNum(temp);
                
                if(p - c == 1) {
                    if(calc(s, j + 1, temp, count + 1)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool splitString(string s) {
        return calc(s, 0, "", 0);
    }
};
class Solution {
public:
    string maxValue(string n, int x) {
        string ans = "";
        bool flag = true;
        if(n[0] == '-') 
        {
            int i = 1;
            
            while(i < n.size()) {
                if((n[i] - '0') > x) {
                    ans += (char)('0' + (x));
                    flag = false;
                    break;
                } else {
                    ans += n[i];
                    i++;
                }
            }
            ans += n.substr(i);
            ans = '-' + ans;
        } 
        else 
        {
            int i = 0;
            while(i < n.size()) {
                if((n[i] - '0') < x) {
                    ans += (char)('0' + (x));
                    flag = false;
                    break;
                } else {
                    ans += n[i];
                    i++;
                }
            }
            ans += n.substr(i);
        }
        
        if(flag) {
            ans += (char)('0' + x);
        }
        
        return ans;
    }
};
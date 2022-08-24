class Solution {
public:
    string addOne(string s) {
        reverse(s.begin(), s.end());
        int carry = 1;
        int i = 0;
        string ans = "";
        
        while(i < s.length() || carry) {
            int sum = 0;
            
            if(i < s.length()) {
                sum += (s[i++]-'0');
            }
            
            sum += carry;
            carry = sum/2;
            ans += to_string(sum%2);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int numSteps(string s) {
        
        int count = 0;
        
        while(s.size() > 1) {
            int t = s.size();
            if(s[t-1]=='0') {
                s = s.substr(0,t-1);
                count++;
            } else {
                s = addOne(s);
                count++;
            }
            
        }
        
        if(s[0]=='0') count++;
        
        return count;
    }
};
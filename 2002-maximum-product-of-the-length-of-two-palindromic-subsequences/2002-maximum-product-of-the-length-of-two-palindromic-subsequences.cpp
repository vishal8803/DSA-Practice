class Solution {
public:
    bool isPalindrome(string &s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
    
    void calc(string &s, int i, string &s1, string &s2, int &ans) {
        if(i==s.length()) {
            if(isPalindrome(s1) && isPalindrome(s2)) {
                int res = s1.size() * s2.size();
                ans = max(ans, res);
            }
            return;
        }
        s1.push_back(s[i]);
        calc(s, i + 1, s1, s2, ans);
        s1.pop_back();
        
        s2.push_back(s[i]);
        calc(s, i + 1, s1, s2, ans);
        s2.pop_back();
        
        calc(s, i + 1, s1, s2, ans);
    }
    
    int maxProduct(string s) {
        int ans = 0;
        
        string s1 = "";
        string s2 = "";
        
        calc(s,0,s1,s2,ans);
        return ans;
    }
};
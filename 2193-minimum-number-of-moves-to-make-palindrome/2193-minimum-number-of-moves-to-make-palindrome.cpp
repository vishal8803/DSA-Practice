class Solution {
public:
    
    int calc(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        
        if(s[0] == s[n-1]) return calc(s.substr(1, n - 2)); 
        
        int i = n - 1;
        while(i > 0) {
            if(s[i] == s[0]) {
                break;
            }
            i--;
        }
        
        if(i == 0) return n/2 + calc(s.substr(1));
        
        string target1 = s.substr(1, i - 1) + s.substr(i+1);
        
        
        return n - i - 1 + calc(target1);
    }
    
    int calc2(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        
        if(s[0] == s[n-1]) return calc2(s.substr(1, n - 2)); 
        
        int j = 0;
        while(j < n - 1) {
            if(s[j] == s[n-1]) {
                break;
            }
            j++;
        }
        if(j == n - 1) {
            return n/2 + calc(s.substr(0, n - 1));
        }
        string target2 = s.substr(0, j) + s.substr(j+1, n - j - 2);
        
        return j + calc2(target2);
    }
    
    int minMovesToMakePalindrome(string s) {
        return min(calc(s), calc2(s));
    }
};
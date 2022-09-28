class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        if(isPalindrome(a) || isPalindrome(b)) return true;
        
        int i = 0;
        int j = b.size() - 1;
        
        while(i < j && a[i]==b[j]) {
            i++;
            j--;
        }
        
        string s1 = a.substr(i, j-i+1);
        string s2 = b.substr(i, j-i+1);
        
        if(isPalindrome(s1) || isPalindrome(s2))return true;
        
        swap(a,b);
        
        i = 0;
        j = b.size() - 1;
        
        while(i < j && a[i]==b[j]) {
            i++;
            j--;
        }
        
        s1 = a.substr(i, j-i+1);
        s2 = b.substr(i, j-i+1);
        
        if(isPalindrome(s1) || isPalindrome(s2))return true;
        
        
        return false;
    }
};
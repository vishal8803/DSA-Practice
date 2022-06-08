class Solution {
public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.length()-1;
        
        while(i < j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(isPalindrome(s))
            return 1;
        
        int a[2];
        a[0]=0;
        a[1]=0;
        
        for(char ch : s){
            if(ch=='a'){
                a[0] = 1;
            }else{
                a[1] = 1;
            }
        }
        
        int sum = a[0] + a[1];
        
        return sum;
    }
};
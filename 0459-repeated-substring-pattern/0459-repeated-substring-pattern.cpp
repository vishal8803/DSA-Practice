class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = "";
        for(int i = 0; i < s.length()-1; i++){
            temp += s[i];
            
            string test = "";
            while(test.length()<s.length()){
                test+=temp;
            }
            if(test==s)
                return true;
        }
        
        return false;
    }
};
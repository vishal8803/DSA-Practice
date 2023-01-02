class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ac = true, nc = true, fc = true;
        if(word[0]>='A' && word[0]<='Z'){
            fc = true;
            ac = true;
            nc = false;
        }else{
            fc = false;
            ac = false;
            nc = true;
        }
        for(int i = 1; i < word.length(); i++){
            if(word[i]>='A' && word[i]<='Z'){
                ac=ac&true;
                nc=nc&false;
                fc=fc&false;
            }else{
                ac=ac&false;
                nc=nc&true;
                // fc=fc&false;
            }
        }
        return ac||fc||nc;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        while(j<s.length()){
            while(j<s.length() && s[j]!=' '){
                j++;
            }
            reverse(s.begin()+i,s.begin()+j);
            j++;
            i=j;
        }
        return s;
    }
};
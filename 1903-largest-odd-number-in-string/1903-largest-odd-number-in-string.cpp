class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int idx = -1;
        for(int i = 0; i < num.size(); i++) {
            if((num[i] - '0')%2 == 1) {
                idx = i;
            }
        }
        if(idx == -1) return "";
        return num.substr(0, idx + 1);
    }
};
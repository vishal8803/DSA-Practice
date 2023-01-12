class Solution {
public:
    string replace(string &s, char src, char dest) {
        string res = s;
        for(int i = 0; i < res.size(); i++) {
            if(res[i] == src) res[i] = dest;
        }
        
        return res;
    }
    
    int maxDiff(int num) {
        int diff = 0;
        string s = to_string(num);
        
        for(char ch : s) {
            for(int j = 0; j <= 9; j++) {
                
                string temp1 = replace(s, ch, (char)('0' + j));
                
                for(char ch2 : s) {
                    for(int l = 0; l <= 9; l++) {
                        
                        string temp2 = replace(s, ch2, (char)('0' + l));
                        int num1 = stoi(temp1);
                        int num2 = stoi(temp2);
                        if(to_string(num1).size() == temp1.size() and to_string(num2).size() == temp2.size() and num1 != 0 and num2 != 0)
                            diff = max(diff, num2 - num1);
                    }
                }
            }
        }
        
        return diff;
    }
};
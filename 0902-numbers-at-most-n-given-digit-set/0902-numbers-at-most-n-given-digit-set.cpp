class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int count = 0;
        string s = to_string(n);
        int size = digits.size();
        
        for(int i = 1; i < s.size(); i++) {
            count += pow(size,i);
        }
        
        for(int i = 0; i < s.size(); i++) {
            bool flag = false;
            for(int j = 0; j < size; j++) {
                if(digits[j][0] < s[i]) {
                    count += pow(size, s.size() - i - 1);
                } else if(digits[j][0] == s[i]) {
                    flag = true;
                }
            }
            if(!flag) return count;
        }
        
        return 1 + count;
    }
};
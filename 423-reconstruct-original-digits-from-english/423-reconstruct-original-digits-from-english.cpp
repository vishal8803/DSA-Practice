class Solution {
public:
    string originalDigits(string s) {
        vector<int> freq(26,0);
        
        for(char ch : s){
            freq[ch-'a']++;
        }
        
        vector<int> digits(10,0);
        
        digits[0] = freq['z'-'a'];
        digits[2] = freq['w'-'a'];
        digits[4] = freq['u'-'a'];
        digits[6] = freq['x'-'a'];
        digits[8] = freq['g'-'a'];
        digits[1] = freq['o'-'a'] - digits[2] - digits[4] - digits[0];
        digits[3] = freq['h'-'a'] - digits[8];
        digits[5] = freq['f'-'a'] - digits[4];
        digits[7] = freq['s'-'a'] - digits[6];
        digits[9] = freq['i'-'a'] - digits[5] - digits[6] - digits[8];
        
        string ans = "";
        for(int i = 0; i < 10; i++){
            if(digits[i]>0){
                while(digits[i]--){
                    ans.append(to_string(i));
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    
    bool isDigit(char ch) {
        if(ch >= '0' and ch <= '9') return true;
        return false;
    }
    
    bool isUpper(char ch) {
        if(ch >= 'A' and ch <= 'Z') return true;
        return false;
    }
    
    bool isLower(char ch) {
        if(ch >= 'a' and ch <= 'z') return true;
        return false;
    }
    
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<int>> freq(65, vector<int>(65, 0));
        
        for(auto m : mappings) {
            char ch1 = m[0];
            char ch2 = m[1];
            
            int val1, val2;
            
            if(isLower(ch1)) val1 = (ch1 - 'a');
            else if(isUpper(ch1)) val1 = 26 + (ch1 - 'A');
            else val1 = 52 + (ch1 - '0');
            
            if(isLower(ch2)) val2 = (ch2 - 'a');
            else if(isUpper(ch2)) val2 = 26 + (ch2 - 'A');
            else val2 = 52 + (ch2 - '0');
            
            freq[val1][val2] = 1;
        }
    
        
        for(int i = 0; i <= s.size() - sub.size(); i++) {
            string temp = s.substr(i, sub.size());
            
            bool flag = true;
            for(int j = 0; j < temp.size(); j++) {
                if(temp[j] == sub[j] ) continue;
                char ch1 = temp[j];
                char ch2 = sub[j];
                
                int val1, val2;

                if(isLower(ch1)) val1 = (ch1 - 'a');
                else if(isUpper(ch1)) val1 = 26 + (ch1 - 'A');
                else val1 = 52 + (ch1 - '0');

                if(isLower(ch2)) val2 = (ch2 - 'a');
                else if(isUpper(ch2)) val2 = 26 + (ch2 - 'A');
                else val2 = 52 + (ch2 - '0');
                
                if(!freq[val2][val1])  {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};
class Solution {
public:
    bool calc(long long n1, long long n2, string s, bool found) {
        if(s.size() == 0 and found) return true;
        
        string s3 = to_string(n1 + n2);
        long long n3 = stol(s3);
        int idx = min(s.size(), s3.size());
        
        if(s.substr(0, idx) == s3) {
            return calc(n2, n3, s.substr(idx), true);
        }
        
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        int n = num.size();
        
        for(int i = 1 ; i < n - 1; i++) {
            string s1 = num.substr(0,i);
            
            long long n1 = stol(s1);
            
            if(to_string(n1) != s1) {
                break;
            }
            
            for(int j = i + 1; j < n; j++) {
                string s2 = num.substr(i, j - i);
                
                long long n2 = stol(s2);
                
                if(to_string(n2) != s2) {
                    break;
                }
                
                bool flag = calc(n1, n2, num.substr(j), false);
                if(flag) return true;
            }
        }
        
        return false;
    }
};
class Solution {
public:
    int countSubstrings(string s, string t) {
        int count = 0;
        
        for(int i = 0; i < s.length(); i++) 
        {
            for(int j = 0; j < t.length(); j++) 
            {
                int d = 0;
                int ti = i;
                int tj = j;
                
                while(ti < s.length() and tj < t.length()) {
                    if(s[ti] != t[tj]) d++;
                    if(d==1) count++;
                    if(d==2) break;
                    ti++;
                    tj++;
                }
            }
        }
        
        return count;
    }
};
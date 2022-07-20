class Solution {
public:
    string longestPrefix(string s) {
        int i = 1;
        int j = 0;
        int n = s.length();
        
        vector<int> lps(n,0);
        
        while(i<n){
            if(s[i]==s[j]){
                lps[i] = j+1;
                i++;
                j++;
            }
            else{
                if(j>0){
                    j=lps[j-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return s.substr(0,lps[n-1]);
    }
};
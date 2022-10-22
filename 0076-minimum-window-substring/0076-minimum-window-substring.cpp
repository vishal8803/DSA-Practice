class Solution {
public:
    int calc(vector<int> &curr, vector<int> &tar) {
        for(int i = 0; i < 52; i++) {
            if(tar[i] != 0 and curr[i] < tar[i]) return 0;
        }
        return 1;
    }
    
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        
        int len = INT_MAX;
        int fi = -1;
        int i = 0;
        int j = 0;
        
        vector<int> curr(52,0);
        vector<int> tar(52,0);
        
        for(char ch : t) {
            if(ch >= 'A' and ch <= 'Z') {
                tar[ch - 'A' + 26]++;
            } else tar[ch-'a']++;
        }
        
        while(j < s.size()) {
            if(s[j] >= 'A' and s[j] <= 'Z') {
                curr[s[j]-'A' + 26]++;
            } else curr[s[j] - 'a']++;
            
            if(calc(curr, tar) == 0) {
                j++;
            }else if(calc(curr, tar) == 1) {
                if(len > j - i + 1) {
                    len = j - i + 1;
                    fi = i;
                }
                
                while(i <= j and calc(curr,tar)==1) {
                    if(len > j - i + 1) {
                        len = j - i + 1;
                        fi = i;
                    }
                    if(s[i] >= 'A' and s[i] <= 'Z') {
                        curr[s[i]-'A' + 26]--;
                    } else curr[s[i] - 'a']--;
                    
                    i++;
                }
                
                j++;
            } 
        }
        if(fi == -1) return "";
        return s.substr(fi, len);
    }
};
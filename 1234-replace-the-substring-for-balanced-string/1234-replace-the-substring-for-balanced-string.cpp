class Solution {
public:
    bool isValid(vector<int> &freq, int k) {
        for(int i : freq) {
            if(i > k) return false;
        }
        return true;
    }
    
    int balancedString(string s) {
        vector<int> freq(4,0);
        int i = 0;
        int j = 0;
        int mx = INT_MAX;
        
        for(char ch : s) {
            if(ch=='Q') freq[0]++;
            else if(ch=='W') freq[1]++;
            else if(ch=='E') freq[2]++;
            else freq[3]++;
        }
        
        int k = s.length()/4;
        
        if(isValid(freq, k)) return 0;
        
        while(j < s.length()) {
            if(s[j]=='Q') freq[0]--;
            else if(s[j]=='W') freq[1]--;
            else if(s[j]=='E') freq[2]--;
            else freq[3]--;
            
            if(isValid(freq, k)) {
                mx = min(mx, j-i+1);
                while(i < j && isValid(freq, k)) {
                    if(s[i]=='Q') freq[0]++;
                    else if(s[i]=='W') freq[1]++;
                    else if(s[i]=='E') freq[2]++;
                    else freq[3]++;
                    i++;
                    if(i < j && isValid(freq,k)) {
                        mx = min(mx, j-i+1);
                    }
                }
                j++;
            } else {
                j++;
            }
        }
        
        return mx;
    }
};
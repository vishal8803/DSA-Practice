class Solution {
public:
    int calc(string s, char ch1, char ch2) {
        int f1 = 0;
        int f2 = 0;
        int ans = INT_MIN;
        
        for(char ch : s) {
            if(ch == ch1) f1++;
            else if(ch == ch2) f2++;
            if(f1 < f2) {
                f1 = 0;
                f2 = 0;
            }
            if(f1 > 0 and f2 > 0 and f1 >= f2) ans = max(ans, f1 - f2);
            
        }
        
        
        return ans;
    }
    
    int largestVariance(string s) {
        int mx = 0;
        vector<int> freq(26,0);
        
        for(char ch : s) {
            freq[ch-'a']++;
        }
        
        vector<char> v;
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0)
                v.push_back('a' + i);
        }
        
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                for(int rev = 1; rev <= 2; rev++){
                    if(j == i) continue;

                    int temp = calc(s, v[i], v[j]);
                    mx = max(mx, temp);
                    reverse(s.begin(), s.end());
                }
            }
        }
        
        return mx;
        
    }
};
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> prefix(n), suffix(n);
        int count = 0;
        vector<int> f(26,0);
        
        for(int i = 0; i < n; i++) {
            f[s[i]-'a']++;
            prefix[i] = f;
        }
        
        vector<int> f2(26,0);
        
        for(int i = n - 1; i >= 0; i--) {
            f2[s[i]-'a']++;
            suffix[i] = f2;
        }
        
        vector<vector<int>> used(26,vector<int>(26,0));
        
        for(int i = 1; i < n - 1; i++) {
            
            vector<int> v1 = prefix[i-1];
            vector<int> v2 = suffix[i+1];

            for(int j = 0; j < 26; j++) {
                if(v1[j] and v2[j] and used[s[i]-'a'][j]==0) {
                    count++; 
                    used[s[i]-'a'][j]++;
                }
            }
        }
        
        return count;
    }
};
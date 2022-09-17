class Solution {
public:
    bool isPalindrome(string &s) {
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        int n = words.size();
        
        for(int i = 0; i < n; i++) {
            auto it = words[i];
            reverse(it.begin(), it.end());
            mp[it] = i;
        }
        
        vector<int> palindromeIndex;
        for(int i = 0; i < n; i++) {
            if(isPalindrome(words[i])) {
                palindromeIndex.push_back(i);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(words[i]=="") {
                
                for(int j : palindromeIndex) {
                    
                    if(j != i ) {
                        ans.push_back({i,j});
                    }
                }
            }
            for(int j = 0; j < words[i].size(); j++) {
                string s1 = words[i].substr(0,j);
                string s2 = words[i].substr(j);
                
                if(mp.count(s2) > 0 && isPalindrome(s1) && mp[s2] != i) {
                    ans.push_back({mp[s2], i});
                }
                
                if(mp.count(s1) > 0 && isPalindrome(s2) && mp[s1] != i) {
                    ans.push_back({i, mp[s1]});
                }
            }
        }
        
        return ans;
    }
};
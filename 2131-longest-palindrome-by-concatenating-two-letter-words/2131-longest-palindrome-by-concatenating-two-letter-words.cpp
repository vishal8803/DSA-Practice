class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        bool flag = false;
        int count = 0;
        map<string,int> mp;
        int extra = 0;
        
        for(string s : words) mp[s]++;
        
        for(string word : words) {
            if(word[0] == word[1]) {
                // count += 2;
            } else {
                string s = word;
                reverse(s.begin(), s.end());
                if(mp[s] > 0) {count += 2; mp[s]--;}
            }
        }
        
        for(auto it : mp) {
            string s = it.first;
            int f = it.second;
            if(s[0] == s[1]) {
                if(f%2) {
                    if(!flag) {
                        count += f*2;
                        flag = true;
                    } else {
                        count += (f-1)*2;
                    }
                } else {
                    count += f*2;
                }
            }
        }
        
        return count;
    }
};
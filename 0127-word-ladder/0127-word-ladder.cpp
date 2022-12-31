class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(string s : wordList) {
            st.insert(s);
        }
        
        map<string,int> mp;
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 0;
        int level = 0;
        
        while(q.size() > 0) {
            int size = q.size();
            level++;
            while(size--) {
                string s = q.front();
                q.pop();
                
                mp[s] = level;
                
                for(int i = 0; i < s.size(); i++) {
                    char original = s[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        s[i] = ch;
                        if(st.find(s) != st.end()) {
                            st.erase(s);
                            q.push(s);
                        }
                    }
                    s[i] = original;
                }
            }
        }
        
        return mp[endWord];
    }
};
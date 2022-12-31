class Solution {
public:
    void ladderLength(string beginWord, string endWord, vector<string>& wordList, map<string,int> &mp) {
        unordered_set<string> st;
        
        for(string s : wordList) {
            st.insert(s);
        }
        
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        int level = 1;
        
        while(q.size() > 0) {
            int size = q.size();
            level++;
            while(size--) {
                string s = q.front();
                q.pop();
                
                if(mp[s] != 0)
                mp[s] = min(level, mp[s]);
                else mp[s] = level;
                
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
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> mp;
        vector<vector<string>> ans;
        
        ladderLength(beginWord, endWord, wordList, mp);
        
        // for(auto it : mp) {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }   
        
        queue<vector<string>> q;
        q.push({endWord});
        
        while(q.size() > 0) {
            vector<string> v = q.front();
            q.pop();
            
            string lastWord = v.back();
            if(lastWord == beginWord) {
                if(ans.size() == 0 or ans[0].size() == v.size()) {
                    reverse(v.begin(), v.end());
                    ans.push_back(v);
                }
            }
            
            // cout<<lastWord<<endl;
            
            for(int i = 0; i < lastWord.size(); i++) {
                string s = lastWord;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;
                    if(mp.find(s) != mp.end() and mp[s] < mp[lastWord]) {
                        v.push_back(s);
                        q.push(v);
                        v.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};
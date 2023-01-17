class Solution {
public:
    bool isValid(map<char,int> &mp) {
        if(mp.size() == 1) return true;
        else if(mp.size() == 2) {
            int mn = INT_MAX;
            for(auto &it : mp) {
                mn = min(mn, it.second);
            }
            if(mn != 1) return false;
            return true;
        }
        return false;
    }
    
    int maxRepOpt1(string text) {
        map<char,int> mp;
        int res = 1;
        int i = 0, j = 0;
        
        int n = text.size();
        
        vector<vector<int>> prefix(n + 1, vector<int>(26, 0));
        vector<vector<int>> suffix(n + 1, vector<int>(26, 0));
        
        vector<int> f(26, 0);
        for(int i = 0; i < n; i++) {
            f[text[i] - 'a']++;
            prefix[i+1] = f;
        }
        
        vector<int> f2(26, 0);
        
        for(int i = n-1; i >= 0; i--) {
            f2[text[i] - 'a']++;
            suffix[i] = f2;
        }
        
        while(j < text.size()) {
            mp[text[j]]++;
            if(isValid(mp)) {
                if(mp.size() == 1){
                    res = max(res, j - i + 1);
                }
                else {
                    char ch = '#';
                    int count = 0;
                    for(auto it : mp) {
                        if(it.second != 1 or ch == '#') ch = it.first;
                        if(it.second == 1) count++;
                    }
                    if(count == 2) {
                        auto it = mp.begin();
                        char ch = it->first;
                        if(prefix[i][ch - 'a'] > 0 or suffix[j+1][ch - 'a'] > 0) {
                            res = max(res, 2);
                        }
                        it++;
                        ch = it->first;
                        if(prefix[i][ch - 'a'] > 0 or suffix[j+1][ch - 'a'] > 0) {
                            res = max(res, 2);
                        }
                    }
                    // cout<<ch<<" ";
                    else if(prefix[i][ch-'a'] > 0 or suffix[j+1][ch - 'a'] > 0)
                        res = max(res, j - i + 1);
                    else
                        res = max(res, j - i);
                }
                j++;
            } else {
                while(i <= j and !isValid(mp)) {
                    mp[text[i]]--;
                    if(mp[text[i]] == 0) mp.erase(text[i]);
                    i++;
                }
                
                if(i <= j and isValid(mp)) {
                    if(mp.size() == 1)
                        res = max(res, j - i + 1);
                    else{
                        char ch = '#';
                        for(auto it : mp) {
                            if(it.second != 1 or ch == '#') ch = it.first;
                        }
                        if(prefix[i][ch-'a'] > 0 or suffix[j+1][ch - 'a'] > 0)
                            res = max(res, j - i + 1);
                        else
                            res = max(res, j - i);
                    }
                }
                j++;
            }
            // cout<<res<<" "<<i<<" "<<j<<" "<<mp.size()<<endl;
        }
        
        return res;
    }
};
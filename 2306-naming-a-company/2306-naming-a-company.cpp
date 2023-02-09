class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        set<string> val[26];
        
        for(string idea : ideas) {
            val[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        long long count = 0;
        
        for(int i = 0; i < 25; i++) {
            for(int j = i + 1; j < 26; j++) {
                int common = 0;
                
                for(auto it : val[i]) {
                    if(val[j].find(it) != val[j].end()) {
                        common++;
                    }
                }
                
                count += 2LL * (long long)(val[i].size() - common) * (long long)(val[j].size() - common);
            }
        }
        
        return count;
    }
};
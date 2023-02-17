class Solution {
public:
    int getMask(string &s) {
        int mask = 0;
        for(char ch : s) {
            mask = mask | (1<<(ch-'a'));
        }
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = puzzles.size();
        map<int, vector<int>> mp;
        
        for(string &word : words) {
            int mask = getMask(word);
            
            for(int i = 0; i < 26; i++) {
                if(mask&(1<<i)) {
                    mp[i].push_back(mask);
                }
            }
        }
        
        vector<int> ans;
        map<string, int> temp;
        temp.clear();
        for(string &puzzle : puzzles) {
            if(temp.find(puzzle) != temp.end()) {
                ans.push_back(temp[puzzle]);
                continue;
            }
            int mask = getMask(puzzle);
            vector<int> possible = mp[puzzle[0] - 'a'];
            
            int count = 0;
            for(int &m : possible) {
                if((m&mask) == m) count++;
            }
            
            ans.push_back(count);
            temp[puzzle] = count;
        }
        
        return ans;
    }
};
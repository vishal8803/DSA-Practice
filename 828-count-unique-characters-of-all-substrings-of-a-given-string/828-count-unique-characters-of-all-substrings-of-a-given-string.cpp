class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> temp(26);
        
        for(int i = 0; i < 26; i++) {
            temp[i].push_back(-1);
        }
        
        for(int i = 0; i < s.length(); i++) {
            temp[s[i]-'A'].push_back(i);
        }
        
        for(int i = 0; i < 26; i++) {
            temp[i].push_back(s.length());
        }
        
        long long count = 0;
        
        for(int i = 0; i < 26; i++) {
            for(int j = 1; j < temp[i].size()-1; j++) {
                count += (temp[i][j]-temp[i][j-1]) * (temp[i][j+1]-temp[i][j]);
            }
        }
        
        return count;
    }
};
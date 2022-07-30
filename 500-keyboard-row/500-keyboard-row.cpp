class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        vector<int> freq(26,0);
        
        for(int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            bool find = false;
            for(char c : row1) {
                if(ch==c) {
                    freq[i] = 1;
                    find = true;
                    break;
                }
            }
            if(find) continue;
            for(char c : row2) {
                if(ch==c) {
                    freq[i] = 2;
                    find = true;
                    break;
                }
            }
            if(find) continue;
            for(char c : row3) {
                if(ch==c) {
                    freq[i] = 3;
                    find = true;
                    break;
                }
            }
            if(find) continue;
        }
        
        for(string word : words) {
            int rowNum = freq[tolower(word[0])-'a'];
            bool canTake = true;
            for(int i = 1; i < word.size(); i++) {
                if(rowNum != freq[tolower(word[i])-'a']){
                    canTake = false;
                    break;
                }
            }
            if(canTake) ans.push_back(word);
        }
        
        return ans;
    }
};
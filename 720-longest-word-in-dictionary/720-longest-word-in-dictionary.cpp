class Solution {
public:
    string longestWord(vector<string>& words) {
        set<string> st;
        
        for(string word : words){
            st.insert(word);
        }
        
        string ans = "";
        
        for(string word : words){
            bool flag = true;
            string temp = "";
            for(int i = 0; i < word.length()-1; i++){
                temp += word[i];
                if(st.find(temp)==st.end()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(ans.length() < word.length()){
                    ans = word;
                }else if(ans.length() == word.length() && ans > word){
                    ans = word;
                }
            }
        }
        return ans;
    }
};
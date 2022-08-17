class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> temp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        
        for(string word : words) {
            string transform = "";
            for(char ch : word) {
                transform += temp[ch-'a'];
            }
            st.insert(transform);
        }
        
        return st.size();
    }
};
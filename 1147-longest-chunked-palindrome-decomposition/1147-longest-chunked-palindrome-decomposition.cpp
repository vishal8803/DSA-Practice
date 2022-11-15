class Solution {
public:
    int longestDecomposition(string text) {
        if(text.size() == 0) return 0;
        
        int i = 0;
        string temp = "";
        
        while(i < text.size()/2) {
            temp += text[i];
            string last = text.substr(text.size() - temp.size());
            
            if(temp == last) return 2 + longestDecomposition(text.substr(i + 1, text.size() - 2*temp.size()));
            i++;
        }
        
        return 1;
    }
};
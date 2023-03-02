class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        
        int i = 0;
        
        while(i < chars.size()){
            char ch = chars[i];
            int count = 0;
            while(i<chars.size() && chars[i]==ch){
                count++;
                i++;
            }
            
            if(count==1){
                s += ch;
            }
            else{
                s += ch;
                s += to_string(count);
            }
        }
        vector<char> temp;
        for(char ch : s){
            temp.push_back(ch);
        }
        chars = temp;
        return s.length();
        
    }
};
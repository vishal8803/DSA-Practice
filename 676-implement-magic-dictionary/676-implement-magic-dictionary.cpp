class MagicDictionary {
public:
    vector<string> temp;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        temp = dictionary;
    }
    
    bool search(string searchWord) {
        for(string s : temp){
            if(s.length()==searchWord.length()){
                int diff = 0;
                for(int i = 0; i < s.length(); i++){
                    if(s[i] != searchWord[i])
                        diff++;
                }
                if(diff==1)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
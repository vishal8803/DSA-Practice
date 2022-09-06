class CombinationIterator {
    string s;
    vector<string> comb;
    int i;
public:
    
    void calc(int cl) {
        int t = (1<<s.length());
        
        for(int i = 0; i < t; i++) {
            string r = "";
            
            for(int j = 0; j < s.length(); j++) {
                if((i>>j)&1) {
                    r += s[s.length()-j-1];
                }
            }
            
            reverse(r.begin(), r.end());
            if(r.size()==cl) {
                comb.push_back(r);
            }
        }
        
    }
    
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        i = 0;
        calc(combinationLength);
        sort(comb.begin(), comb.end());
    }
    
    string next() {
        return comb[i++];
    }
    
    bool hasNext() {
        if(i>comb.size()-1) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class AllOne {
public:
    unordered_map<string,int> mp;
    set<pair<int,string>> st;
    
    AllOne() {
        
    }
    
    void inc(string key) {
        int f = mp[key];
        if(f == 0){
            mp[key]++;
            st.insert({mp[key], key});
        } else {
            st.erase(st.find({mp[key], key}));
            mp[key]++;
            st.insert({mp[key], key});
        }
    }
    
    void dec(string key) {
        int f = mp[key];
        if(f == 1){
            mp[key]--;
            st.erase({1, key});
        } else if(f > 1) {
            st.erase(st.find({mp[key], key}));
            mp[key]--;
            st.insert({mp[key], key});
        }
    }
    
    string getMaxKey() {
        if(st.size() == 0) return "";
        
        return (*st.rbegin()).second;
    }
    
    string getMinKey() {
        if(st.size() == 0) return "";
        
        return (*st.begin()).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */